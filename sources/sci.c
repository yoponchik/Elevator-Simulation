#include "main.h"
unsigned char *txbuffer_sci0; //text�� �����ϴ� �����̴�. 
int txoffset_sci0;            //text���ڿ� ���̸� �˱����� �ʿ��� �����̴�.
unsigned char *rxbuffer_sci0; //rx�� �����ϴ� �����̴�.

int read = 0;
int arraycount = 0;  // initialization(0)
int end = 0;
  // for-loop



/*********************************************************/
/*  �ø��� ��� 0�� ä���� �ʱ�ȭ �Ѵ�.				                       */
/*********************************************************/ 
void init_sci0(int baud_rate, unsigned char *rxbuf) 
{
/*sci�� �ʱ�ȭ �ϴ� �Լ��̴�. bps�� ���ڿ��� ���� �׸��� �ۼ��� interrupt�� ������� ���� �����Ѵ�.*/
  unsigned long oscclk, modclk;  //SCIBD register�� SBR�� �����ϱ� ���� ����
  unsigned short br;    //�츮 ����� �ϴ� bps�� �����ϴ� ����
  br = baud_rate;
  oscclk = 16000000;	  //MCU�� ���ļ��� 16 MHz�̴�.
  modclk = oscclk/2;	  //Set SCI module clock = (Oscillator Freq.)/2
  br = baud_rate;
  //br = 26;   //Set BR, SCI baud rate = (SCI module clock)/(16*BR)  
/*���� �ĵ��� �츮�� ����ϴ� MCU�� ������ ���� �������� ���̴�. */
  //br = 19200;

  Sci0.scibd.word =  26;  //������ BR ���� SCIBD register�� ����
  Sci0.scicr1.byte = 0x00;  //SCI ���� ���� register �ʱ�ȭ. Normal operation & 8 data bit format & Parity disabled
  Sci0.scicr2.byte = 0b00101100; //try transmit interrupt //SCI ���� ���� register �ʱ�ȭ. transmit & receive & receive interrupt Ȱ��ȭ 
/* ���⼭ transmit interrpt�� ���� �� interrupt�� �߻���Ű�� ������ �ʱ�ȭ �� �� �ʿ����. */ 
	txoffset_sci0 = 0;          
	rxbuffer_sci0 = rxbuf;
/*������ offset�� buffer�� �ʱ�ȭ �Ѵ�.*/     
}
/*********************************************************/
/*  �Է¹��� ���ڿ��� �ø��� ������� �����Ѵ�.                          */
/*  �Է¹��� ���ڿ��� ���̸� ���ۿ� �����ϰ� �۽� interrupt�� enable����     */
/*  MCU�� interrupt handler�� �����ϵ��� �Ѵ�.                   */
/*********************************************************/ 
void write_sci0(unsigned char *text)
{
/*�� �Լ��� �Է¹��� ���ڿ��� ��ǻ�Ϳ� ������ ������ �ϴ� �Լ��̴�. transmit interrupt�� �߻����� sci interrupt handler�Լ��� ȣ���ϰ� �ȴ�*/

	txbuffer_sci0 = text;
/*���ڿ� ���̸� offset�� ���� ��Ų��.*/
	Sci0.scicr2.byte |= 0b10001000;         //TIE & TE Ȱ��ȭ

}
/*****************************************************************/
//  �ø��� ��� �۽� �� ���� ���ͷ�Ʈ�� �߻����� �� ó���Ǵ� �Լ�.                      
//  �� ����Ʈ�� ���ڰ� �۽� �� ���� �� ������ ���ͷ�Ʈ�� �߻���                        
//  sci�� interrupt TDRE�� RDRF�� �߻����� �� ȣ��Ǵ� �Լ��̴�. ���� ���� �� �Լ��� projectvectors.c�� ����� �Ǿ� �־�� �Ѵ�. ���������� ��Ʈ ���Ͽ� ���� ��/���� ���°� �����ȴ�.        						 
/*****************************************************************/ 
void sci0_handler(void){

  if(Sci0.scisr1.bit.rdrf == 1){   //���� �����̸� RDRF�� �ݵ�� 1�� �Ǿ��ִ�.
      *rxbuffer_sci0 = Sci0.scidrl.byte;  // scidrl�� ����� 1bit ���� �����͸� ���� ���ۿ� ����    
/*�׷��� ������ �����͸� ����ϱ����� rxbuffer�� ù ��° �ڸ����� �����ϰ� �ȴ�. */

       if(*rxbuffer_sci0 == '<'){
          read = 1;
       }
       
       if(*rxbuffer_sci0 == '>') {    // end
          read = 0;
          end = 1;
          rxbuffer_sci0 -= arraycount;
          
          arraycount = 0;
          
       }            
       
       else{
                    
          rxbuffer_sci0 ++;
          arraycount ++;

       }

          
  }
  else if (Sci0.scisr1.bit.tdre == 1){  
/*���� ���°� �ƴ� �۽� �����̸� TDRE�� 1�̵ǰ� ���� ���� status�� ���� �ָ� �ȴ�. */
  
 
    Sci0.scidrl.byte = *txbuffer_sci0;    // scidrl�� �۽��� ������ ����
    txbuffer_sci0++;

    if(*txbuffer_sci0 == '\0')
    {
      Sci0.scicr2.byte &= 0b01111111;           // Transmitter Interrupt Enable Bit�� Ŭ����   //|=??
    }
  }
}





   




