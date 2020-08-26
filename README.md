# Smart Shower, a solução inteligente para seu banho

![Shower](https://github.com/Microcontroladores-2020/FilipeAbelha-SmartShower/blob/master/img/Shower.jpg?raw=true)

## Função e motivação

Bem-vindo ao Smart Shower, um chuveiro inteligente que mantém uma temperatura constante para o seu banho, independentemente se o chuveiro está com pouco ou muito fluxo de água.
* *Cansado(a) de subir numa cadeira para trocar o modo do chuveiro?* Ajuste pelo controle remoto!
* *O dia está muito frio ou muito quente?* Sem problemas, o seu Smart Shower ajustará automaticamente para uma temperatura sugerida entre 15ºC e 38ºC, dependendo da temperatura ambiente.
* *Quer uma temperatura específica?* Saiba que o seu Smart Shower permite ajustá-la com a mesma facilidade que você ajusta o volume de sua televisão.

## Como utilizar

1. Ligue o dispositivo
2. Espere até que o Smart Shower calcule a melhor temperatura para o seu banho
3. Abra o chuveiro e regule o fluxo de água de uma forma confortável
4. Tome seu banho com uma temperatura constante, podendo mudar o fluxo de água à vontade
5. Ao terminar, desligue pelo controle remoto. Assim, na próxima vez, basta ligar pelo controle remoto novamente.

## High-level Design

Construído a partir de um microcontrolador STM32F401RE, o Smart Shower utiliza cinco periféricos: um receptor de sinais infravermelhos de controle remoto, um sensor de temperatura, um sensor de fluxo de água, um potenciômetro digital para regular a resistência do chuveiro e um LED de 7 segmentos com 2 dígitos para exibir a temperatura atual, conforme diagrama a seguir:

![High-level Design](https://github.com/Microcontroladores-2020/FilipeAbelha-SmartShower/blob/master/img/HighLevelDesign.png?raw=true)

## Diagrama de blocos da eletrônica

Um diagrama mais detalhado, evidenciando tanto as relações lógicas como as relações de energia.

![Diagrama](https://github.com/Microcontroladores-2020/FilipeAbelha-SmartShower/blob/master/img/Diagrama.png?raw=true)

## Diagrama de pinagem

Pinos utilizados pelo Smart Shower no STM.

![Pinout](https://github.com/Microcontroladores-2020/FilipeAbelha-SmartShower/blob/master/img/Pinout.png?raw=true)

## Fluxograma do firmware

Lógica utilizada para proporcionar a experiência descrita.

![Fluxograma](https://github.com/Microcontroladores-2020/FilipeAbelha-SmartShower/blob/master/img/Fluxograma.png?raw=true)

## Roadmap

* Expandir a funcionalidade de aumentar e diminuir a temperatura, podendo digitar o número exato pelo controle remoto.
* Criar um segundo modo, no qual o Smart Shower apenas carrega a última temperatura utilizada, sem sugerir uma nova.
