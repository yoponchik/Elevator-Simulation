#include "interrupt.h"

signed char reserved_level;
signed char floor[8];
int i=0;





void ini_interrupt(void){
 
 Pim.ddrj.byte=0b00000000;    // ���ͷ�Ʈ ��Ʈ�� ���� ����
 Pim.piej.byte=0xff;		// ���ͷ�Ʈ ��Ʈ�� ���ͷ�Ʈ enable
 Pim.ppsj.byte=0x00;		// ���ͷ�Ʈ ��Ʈ�� ���� ���� 
  
}



void interruptJ_function(void){
  if(Pim.pifj.byte & 0x01) // SW2�� ���ͷ�Ʈ �߻� 
  { 
    floor[i]='2';
    i++;
    write_string(0x80, floor);
    //load_reservation();
    
   
    Pim.pifj.byte |= 0x01; // ���ͷ�Ʈ �÷��� �ʱ�ȭ 
  } 
  else if(Pim.pifj.byte & 0x02) // SW3�� ���ͷ�Ʈ �߻� 
  { 
    floor[i]='3';
    i++;
    write_string(0x80, floor);
    

    Pim.pifj.byte |= 0x02; // ���ͷ�Ʈ �÷��� �ʱ�ȭ 
  }
}


void interruptX_function (void) //XIRQ interrupt ���� �Լ� 
{	 
  //init_rti(3); 
    floor[i]='1';
    i++;
    write_string(0x80, floor);
  
}







        
