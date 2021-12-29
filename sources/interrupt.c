#include "interrupt.h"

signed char reserved_level;
signed char floor[8];
int i=0;





void ini_interrupt(void){
 
 Pim.ddrj.byte=0b00000000;    // 인터럽트 포트의 방향 결정
 Pim.piej.byte=0xff;		// 인터럽트 포트의 인터럽트 enable
 Pim.ppsj.byte=0x00;		// 인터럽트 포트의 엣지 설정 
  
}



void interruptJ_function(void){
  if(Pim.pifj.byte & 0x01) // SW2의 인터럽트 발생 
  { 
    floor[i]='2';
    i++;
    write_string(0x80, floor);
    //load_reservation();
    
   
    Pim.pifj.byte |= 0x01; // 인터럽트 플래그 초기화 
  } 
  else if(Pim.pifj.byte & 0x02) // SW3의 인터럽트 발생 
  { 
    floor[i]='3';
    i++;
    write_string(0x80, floor);
    

    Pim.pifj.byte |= 0x02; // 인터럽트 플래그 초기화 
  }
}


void interruptX_function (void) //XIRQ interrupt 서비스 함수 
{	 
  //init_rti(3); 
    floor[i]='1';
    i++;
    write_string(0x80, floor);
  
}







        
