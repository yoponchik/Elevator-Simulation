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
/* ����Ÿ�� ���ͷ�Ʈ�� �ʱ�ȭ �Ѵ�.*/
/*************************************************/
void init_rti(int s)
{
	scaler = s;
	Crg.rtictl.byte = 0x17; //����Ÿ�� ���ͷ�Ʈ�� �ӵ� ����(0.5ms �� �Ͻÿ�)
	Crg.crgint.byte |= 0x80;		//����Ÿ�� ���ͷ�Ʈ enable
	
}





/*************************************************/
/* ����Ÿ�� ���ͷ�Ʈ�� �߻��� ���� ������ �����Ѵ�. */
/*************************************************/

/* 0.5�� ���� rti_handler ���� */
void rti_handler(void)
{
	static int count = 0;
	
	count++;

	if (count >= 2000) //5ms
	{
	  count = 0;
	
	}
	// clear flag
Crg.crgflg.bit.rtif = 1; // �ǽð� ���ͷ�Ʈ �÷��� �ʱ�ȭ

}



  
