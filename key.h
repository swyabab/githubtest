#ifndef _KEY_H
#define _KEY_H
#include "stm32f10x.h"
#define KI_PRESSED 0x01
void key_init(void);
char get_key_status(void);


#endif