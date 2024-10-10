#include "led.h"

#define LED_RCC       RCC_APB2Periph_GPIOB
#define LED_GPIO      GPIOB
#define LED_PIN_1     GPIO_Pin_13
#define LED_PIN_2     GPIO_Pin_14

void led_init(){
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(LED_RCC,ENABLE);                       //Ê¹ÄÜGPIOÊ±ÖÓ
  GPIO_InitStructure.GPIO_Pin = LED_PIN_1 |LED_PIN_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(LED_GPIO,&GPIO_InitStructure);
  GPIO_SetBits(LED_GPIO,LED_PIN_1|LED_PIN_2);
}

void turn_off(unsigned char Led){
  if(Led & D1)
    GPIO_SetBits(LED_GPIO, LED_PIN_1);   
  if(Led & D2)
    GPIO_SetBits(LED_GPIO, LED_PIN_2);
}

void turn_on(unsigned char Led){
  if(Led & D1)
    GPIO_ResetBits(LED_GPIO, LED_PIN_1);   
  if(Led & D2)
    GPIO_ResetBits(LED_GPIO, LED_PIN_2);
}