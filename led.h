#ifndef _LED_H
#define _LED_H
#include "stm32f10x.h"
#define D1      0X01                                            //�궨��D1���ֱ��   
#define D2      0X02                                            //�궨��D2���ֱ��
void led_init(void);
void turn_off(unsigned char Led);
void turn_on(unsigned char Led);
#endif