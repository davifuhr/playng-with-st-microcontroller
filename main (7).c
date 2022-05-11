/* Includes */
#include "stm32f4xx.h"



int main(void)
{

	RCC->AHB1ENR = RCC_AHB1ENR_GPIOAEN|RCC_AHB1ENR_GPIOBEN;
	// PB10 PB9 PB8 PB6 COMO SAÍDAS
	GPIOB->MODER=GPIO_MODER_MODER6_1|GPIO_MODER_MODER8_1|GPIO_MODER_MODER9_1|GPIO_MODER_MODER10_1;
	// PA7 PA6 PA5 PA4 COMO ENTRADAS
	 GPIOA->MODER=0xA8000000;
	// PA7 PA6 PA5 PA4 DEFININDO COMO PULL-DOWN
	GPIOA->PUPDR=GPIO_PUPDR_PUPDR4_0|GPIO_PUPDR_PUPDR5_0|GPIO_PUPDR_PUPDR6_0|GPIO_PUPDR_PUPDR7_0;

	uint16_t valor=0;

  /* Infinite loop */
  while (1)
  {
	  valor= GPIOA-> IDR& 0b11110000;

	  switch (valor){

	  case 0b00010000: // ligando PA4
		  GPIOB->ODR=0b00001000000;// ligando led PB6
		  break;
	  case 0b00100000:// apertando PA5
		  GPIOB->ODR=0b0000100000;// ligando PB6 E PB8
		  break;
	  case 0b01000000: // apertando botao PA6
		  GPIOB->ODR=0b1000000000;// ligando led mais significativo PB10
		  break;
	  case 0b10000000: // pressionando bota PA7
		  GPIOB->ODR=0b11000000000; // ligam os leds PB10 E PB9
		  break;

	  default :
		  GPIOB->ODR=0b00000000000;

	  }

  }
