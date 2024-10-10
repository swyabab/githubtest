#include "key.h"
//GPIO GPIO_Pin_9控制LED灯的亮灭
void key_init(void){
  //1.使能时钟,在使用之前需要使能时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  //2.定义GPIO初始化结构体
   GPIO_InitTypeDef GPIO_InitStruct;
   
  //3.给成员变量赋值
  GPIO_InitStruct.GPIO_Pin=GPIO_Pin_9;
   GPIO_InitStruct.GPIO_Speed=GPIO_Speed_2MHz;
   GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
  //4.GPIO_Init();
   GPIO_Init(GPIOB,&GPIO_InitStruct);
  
  
}
//GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
//读取输入电平函数；按键实验使用
//1松开，0按下
char get_key_status(void){
  //记录按键状态
  char key_status=0;
  //GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9);
  if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==0)
    key_status|=KI_PRESSED;
  else
    key_status&=~KI_PRESSED;

  return key_status;
}