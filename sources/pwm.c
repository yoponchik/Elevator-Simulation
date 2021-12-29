#include "main.h"

/*
 * PWM0 -> A
 * PWM1 -> /A
 * PWM2 -> B
 * PWM3 -> /B
 *
 * PWM0, PWM1 ->  62.5kHz
 *
 * ���� Ŭ�� : 8MHz */



/**************************************************/
/*   PWM�� �ʱ�ȭ�Ѵ�.                           */
/**************************************************/

void init_pwm(void) 
{
 
  Pwm.pwme.byte = PWME0 + PWME1 + PWME2 + PWME3;
  //Pwm.pwme.byte = 0x0;  // PWM�� ��� ä��(0~3)�� ��Ȱ��ȭ �Ѵ�.
  
  //Pwm.pwmpol.byte = PPOL1 + PPOL2;  // �� ä���� �ؼ��� �����Ѵ�. //�ð��
  //Pwm.pwmpol.byte = PPOL0 + PPOL2;  //�ݽð� ���� 
  
  Pwm.pwmclk.byte = 0x0;  // �� ä���� Ŭ��(A,B)�� �����Ѵ�.
  
  Pwm.pwmprclk.byte = PCKA2 + PCKA1 + PCKA0 + PCKB2 + PCKB1;  // �� ä���� Clock Prescale �� �����Ѵ�.

  Pwm.pwmcae.byte = CAE2+CAE3;  // �߾� ����(Center Align)�� ä���� �����Ѵ�.
  
  // PWM control
  Pwm.pwmctl.byte = 0x0;
  
  // shutdown
  Pwm.pwmsdn.bit.pwm7en = 0;  
 
}


/**************************************************/
/*   PWM�� �ֱ�� ��Ƽ�� �����Ѵ�.  */
/**************************************************/

void set_pwm(unsigned char p, unsigned char d) 
{

  // disable PWM channel
  //Pwm.pwme.byte = (	);
  
  // �� ä���� �ֱ⸦ �����Ѵ�.
  Pwm.pwmper[0].byte = p;
  Pwm.pwmper[1].byte = p;
  Pwm.pwmper[2].byte = p;
  Pwm.pwmper[3].byte = p;
  
  // �� ä���� ��Ƽ�� �����Ѵ�.
  Pwm.pwmdty[0].byte = d;
  Pwm.pwmdty[1].byte = d;
  Pwm.pwmdty[2].byte = d;
  Pwm.pwmdty[3].byte = d;

 
  // PWM�� ��� ä��(0~3)�� Ȱ��ȭ �Ѵ�.
  //Pwm.pwme.byte = PWME0 + PWME1 + PWME2 + PWME3;
}
