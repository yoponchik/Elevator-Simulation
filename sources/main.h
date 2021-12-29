#ifndef MAIN_H        /*prevent duplicated includes*/
#define MAIN_H

#include <stdio.h>
#include <string.h>

#include "projectglobals.h"

#include "pwm.h"
#include "atd.h"
#include "lcd.h"
#include "rti.h"
#include "interrupt.h"
#include "7segment.h"
#include "sci.h"


unsigned int atdnumber(unsigned int cnt);
void load_7segment(void);
void up_loading_bar1(void);
void up_loading_bar2(void);
void down_loading_bar1(void);
void down_loading_bar2(void);
void door(void);
void buzzer(void);
void delay(unsigned int n);
void down(void);
void up(void);
void movement(void);
unsigned char speedchange();
char load(void);
void floor_reservation(void);
void load_reservation(void);
unsigned int atdnumber(unsigned int cnt);

#endif /*MAIN_H*/