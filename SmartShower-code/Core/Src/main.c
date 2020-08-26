#include "main.h"
#include "stm32f4xx_it.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

void smartShowerInit(uint8_t* t, uint8_t* T, float* F);   // Realiza a rotina de inicialização do dispositivo
void inputTemperaturaAmbiente(uint8_t* t);                // Função para ler a temperatura ambiente e gravar na variável t
void inputFluxoDeAgua(float* F);                          // Função para ler o fluxo de água e gravar na variável F
void outputDisplay(uint8_t* T);                           // Função para atualizar o display com a temperatura atual T
void outputPotenciometro(uint8_t* T, float* F);           // Função para definir a potência P(T, F) e atualizar o potenciômetro para P
void getTemperaturaSugerida(uint8_t* t, uint8_t* T);      // Sugere uma temperatura T entre 15ºC e 38ºC a partir do valor de t
bool estaRecebendoSinal(void);                            // Função para detectar um novo sinal infravermelho
uint8_t decodificaSinal(uint8_t* S);                      /* Função para identificar o tipo S do sinal
                                                             S = 1: aumentar temperatura
                                                             S = 2: diminuir temperatura
                                                             S = 3: desligar o dispositivo */


int main (void) {
  HAL_Init();                                             // Reinicialização de todos os periféricos. Inicializa a interface Flash e o Systick.
  SystemClock_Config();                                   // Configurar o clock do sistema
  MX_GPIO_Init();                                         // Inicializar todos os periféricos

  uint8_t t, T, S;                                        // Declaração das variáveis do dispositivo
  float F;

  smartShowerInit(t, T, F);
  outputDisplay(T);

  /* Loop infinito */
  while (1) {
	  inputFluxoDeAgua(F);                                // "Mede o fluxo de água, F"
	  outputPotenciometro(T, F);                          // "Ajusta o potenciômetro em função de T e F"
	  sleep(100);                                         // "Aguarda..."

	  if (estaRecebendoSinal()) {                         // "Recebendo sinal IR?"
		  decodificaSinal(S);                             // SIM: "Decodifica o sinal"
		  if (S == 1) {                                   // "Aumentar temperatura?"
			  T = T+1;                                    // SIM: "T = T+1"

		  } else if (S == 2) {                            // NÃO: "Diminuir temperatura?"
			  T = T-1;				                      // SIM: "T = T-1"

		  } else if (S == 3) {                            // NÃO: "Desligar?"
			  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;          // Ativa deepsleep
			  __DSB();                                    // Assegura que o efeito do último armazenamento tenha efeito
			  __WFI();                                    // Ativa modo sleep

			  // <espera até detectar novo sinal IR>

			  smartShowerInit(t, T, F);                   // Reinicializando o dispositivo
		  }
		  outputDisplay(T);                               // "Atualiza o LED com o valor de T"
	  }
  }
}

void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

static void MX_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_OUT_LED1A_Pin|GPIO_OUT_LED1B_Pin|GPIO_OUT_LED1C_Pin|GPIO_OUT_LED1D_Pin
                          |GPIO_OUT_LED1E_Pin|GPIO_OUT_LED1F_Pin|GPIO_OUT_LED1G_Pin|GPIO_OUT_POTENTIOMETER_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_OUT_LED1H_Pin|GPIO_OUT_LED2A_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_OUT_LED2B_Pin|GPIO_OUT_LED2C_Pin|GPIO_OUT_LED2D_Pin|GPIO_OUT_LED2E_Pin
                          |GPIO_OUT_LED2F_Pin|GPIO_OUT_LED2G_Pin|GPIO_OUT_LED2H_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : GPIO_OUT_LED1A_Pin GPIO_OUT_LED1B_Pin GPIO_OUT_LED1C_Pin GPIO_OUT_LED1D_Pin
                           GPIO_OUT_LED1E_Pin GPIO_OUT_LED1F_Pin GPIO_OUT_LED1G_Pin GPIO_OUT_POTENTIOMETER_Pin */
  GPIO_InitStruct.Pin = GPIO_OUT_LED1A_Pin|GPIO_OUT_LED1B_Pin|GPIO_OUT_LED1C_Pin|GPIO_OUT_LED1D_Pin
                          |GPIO_OUT_LED1E_Pin|GPIO_OUT_LED1F_Pin|GPIO_OUT_LED1G_Pin|GPIO_OUT_POTENTIOMETER_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : GPIO_OUT_LED1H_Pin GPIO_OUT_LED2A_Pin */
  GPIO_InitStruct.Pin = GPIO_OUT_LED1H_Pin|GPIO_OUT_LED2A_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : GPIO_OUT_LED2B_Pin GPIO_OUT_LED2C_Pin GPIO_OUT_LED2D_Pin GPIO_OUT_LED2E_Pin
                           GPIO_OUT_LED2F_Pin GPIO_OUT_LED2G_Pin GPIO_OUT_LED2H_Pin */
  GPIO_InitStruct.Pin = GPIO_OUT_LED2B_Pin|GPIO_OUT_LED2C_Pin|GPIO_OUT_LED2D_Pin|GPIO_OUT_LED2E_Pin
                          |GPIO_OUT_LED2F_Pin|GPIO_OUT_LED2G_Pin|GPIO_OUT_LED2H_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : GPIO_IN_WATER_FLUX_Pin GPIO_IN_IR_RECEIVER_Pin GPIO_IN_TEMPERATURE_Pin */
  GPIO_InitStruct.Pin = GPIO_IN_WATER_FLUX_Pin|GPIO_IN_IR_RECEIVER_Pin|GPIO_IN_TEMPERATURE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

void Error_Handler(void) {
}


void smartShowerInit(uint8_t* t, uint8_t* T, float* F) {
	 /* Inicialização das variáveis do dispositivo. T ganha o valor de 88 para realizar um sanity check
		mostrando ao usuário pelo LED que o dispositivo ligou com sucesso. */
	  t = 0;
	  T = 88;
	  F = 0;
	  S = 0;

	  outputDisplay(T);             // Imprime o sanity check para mostrar que o dispositivo ligou com sucesso
	  inputTemperaturaAmbiente(t);  // "Mede a temperatura externa, t"
	  getTemperaturaSugerida(t, T); // "Calcula a temperatura ideal T em função de t"
}

void inputTemperaturaAmbiente(uint8_t* t) {
    // A completar
}

void inputFluxoDeAgua(float* F) {
    // A completar
}

void outputDisplay(uint8_t* T) {
    // A completar
}

void outputPotenciometro(uint8_t* T, float* F) {
    // A completar
}

void getTemperaturaSugerida(uint8_t* t, uint8_t* T) {
    // A completar
}

bool estaRecebendoSinal(void) {
    // A completar
}

uint8_t decodificaSinal(uint8_t* S) {
    // A completar
}
