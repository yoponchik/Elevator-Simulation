#include "rti.h"

int scaler;
int pin = 0x01;

extern unsigned char pwm;
extern signed char buffer[8];
extern signed char reserved_level, standby_level;
extern int current_level; 







// s : scaler by 0.5ms
// eg) s=2000 -> 0.5*2000 = 1s

/*************************************************/
/* 리얼타임 인터럽트를 초기화 한다.*/
/*************************************************/
void init_rti(int s)
{
	scaler = s;
	Crg.rtictl.byte = 0x17; //리얼타임 인터럽트의 속도 결정(0.5ms 로 하시오)
	Crg.crgint.byte |= 0x80;		//리얼타임 인터럽트 enable
	
}





/*************************************************/
/* 리얼타임 인터럽트가 발생할 때의 동작을 정의한다. */
/*************************************************/

/* 0.5초 마다 rti_handler 실행 */
void rti_handler(void)
{
	static int count = 0;
	
	count++;

	if (count >= 2000) //5ms
	{
	  count = 0;
	
	}
	// clear flag
Crg.crgflg.bit.rtif = 1; // 실시간 인터럽트 플래그 초기화

}



  
