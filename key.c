#include "key.h"
//GPIO GPIO_Pin_9����LED�Ƶ�����
void key_init(void){
  //1.ʹ��ʱ��,��ʹ��֮ǰ��Ҫʹ��ʱ��
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  //2.����GPIO��ʼ���ṹ��
   GPIO_InitTypeDef GPIO_InitStruct;
   
  //3.����Ա������ֵ
  GPIO_InitStruct.GPIO_Pin=GPIO_Pin_9;
   GPIO_InitStruct.GPIO_Speed=GPIO_Speed_2MHz;
   GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
  //4.GPIO_Init();
   GPIO_Init(GPIOB,&GPIO_InitStruct);
  
  
}
//GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
//��ȡ�����ƽ����������ʵ��ʹ��
//1�ɿ���0����
char get_key_status(void){
  //��¼����״̬
  char key_status=0;
  //GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9);
  if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==0)
    key_status|=KI_PRESSED;
  else
    key_status&=~KI_PRESSED;

  return key_status;
}