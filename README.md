# Acionamento-Remoto-RF
Esse projeto consiste em acionamento remoto via rádio frequência com a utilização de duas placas arduinos NANO, dois módulos nRF24L01, dois conversores de 110/220vac 
para 5 vdc, um módulo relé, uma contatora.

O projeto consiste na utilização da biblioteca SPI.h, nRF24L01.h, RF24.h.
No programa de Rx o programa é simples, tem as definições de entrada para execução do programa, ja no SETUP parametrizo o modulo RF e portas de saidas, 
no LOOP, o controle de fluxo é realizado através de uma série de IF's, sendo o primeiro para verificar se o modulo TX esta diponivel e em seguida verificações dos
estados das portas no modulo TX e atualização nas portas correspondentes no RX.

O programa do TX consiste nas mesmas defifinições do RX, no SETUP a unica diferenca entre o TX e RX é que ele tem o comando de parar de ouvir e as definições das
portas de entrada, no LOOP ele faz a leitura das portas e informa as mesmas via RF.
