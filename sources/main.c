
#include <stdlib.h>
#include "main.h"
#include "projectglobals.h"    


            
unsigned extern char pwm;     
extern signed char reserved_level;
int current_level=1; 
extern signed char floor[8];    
unsigned int cnt;
int n=0;   
unsigned char pwm; 
extern int i;

                            
               
void main()
{            
  int_disable();     //interrupt disable
  ini_interrupt();     //initiate interrupt
  int_enable();         //enable interrupt
  xint_enable();       //enable switch3 interrupt
  init_pwm();           //initiate motor
  init_atd0();          //initiate potentiometer
  init_LCD();            //initiate LCD          
  init_7segment();
  
   
                           
  
  while(1){
  
    movement();
    delay(50);
     
  }

      
      
}

  // 층수마다 7segment 에 표시 
void load_7segment(void){
  
    
    if(reserved_level==49){          //예약된 층이 1층이면 
       set_7segment(1);             //7segment에 1층을 표시 
                 //예약되어있는 배열들을 한칸씩 땡긴다(첫번째 배열에 있던 값이 load되서)
                 //현재층이 1층으로 된다.
    }
    if(reserved_level==50){          //예약된 층이 2층이면 
       set_7segment(2);             //7segment에 2층을 표시
                //예약되어있는 배열들을 한칸씩 땡긴다(첫번째 배열에 있던 값이 load되서)
                 //현재층이 2층으로 된다.
    }                               
    if(reserved_level==51){          //예약된 층이 3층이면
       set_7segment(3);             //7segment에 3층을 표시 
                 //예약되어있는 배열들을 한칸씩 땡긴다(첫번째 배열에 있던 값이 load되서)
                  //현재층이 3층으로 된다.
    }
    
    
 //  }
}


  // 상승시점 시계방향으로 loadingbar 동작 
void up_loading_bar1(void){

      Pim.pth.byte=0;
      
       Pim.pth.byte=0b00000001;
       write_string(0xc5, "*");
       delay(5);   
       Pim.pth.byte=0b00000010;
       write_string(0xc5, " *");
       delay(5);
       Pim.pth.byte=0b00000100;
       write_string(0xc5, "  *");
       delay(5);
       Pim.pth.byte=0b00001000;
       write_string(0xc5, "   *");
       delay(5);
       Pim.pth.byte=0b00010000;
       write_string(0xc5, "    *");
       delay(5);
       Pim.pth.byte=0b00100000;
       write_string(0xc5, "     *");
       delay(5);
       write_string(0xc5, "      ");
       delay(5);
}

void up_loading_bar2(void){

      Pim.pth.byte=0;
      
       Pim.pth.byte=0b00000001;
       write_string(0xc5, "*");
       delay(5);   
       Pim.pth.byte=0b00000010;
       write_string(0xc5, " *");
       delay(5);
       Pim.pth.byte=0b00000100;
       write_string(0xc5, "  *");
       delay(5);
       Pim.pth.byte=0b00001000;
       write_string(0xc5, "   *");
       delay(5);
       Pim.pth.byte=0b00010000;
       write_string(0xc5, "    *");
       delay(5);
       Pim.pth.byte=0b00100000;
       write_string(0xc5, "     *");
       delay(5);
       Pim.pth.byte=0b00000001;
       write_string(0xc5, "      *");
       delay(5);   
       Pim.pth.byte=0b00000010;
       write_string(0xc5, "       *");
       delay(5);
       Pim.pth.byte=0b00000100;
       write_string(0xc5, "        *");
       delay(5);
       Pim.pth.byte=0b00001000;
       write_string(0xc5, "         *");
       delay(5);
       Pim.pth.byte=0b00010000;
       write_string(0xc5, "          *");
       delay(5);
       Pim.pth.byte=0b00100000;
       write_string(0xc5, "           *");
       delay(5);
       write_string(0xc5, "            ");
       delay(5);
       

}
      
      
void down_loading_bar1(void){
      
      Pim.pth.byte=0;
      

        Pim.pth.byte=0b00000001;
        write_string(0xc5, "*");
        delay(5); 
        Pim.pth.byte=0b00100000;
        write_string(0xc5, " *");
        delay(5);
        Pim.pth.byte=0b00010000;
        write_string(0xc5, "  *");
        delay(5);
        Pim.pth.byte=0b00001000;
        write_string(0xc5, "   *");
        delay(5);
        Pim.pth.byte=0b00000100;
        write_string(0xc5, "    *");
        delay(5);
        Pim.pth.byte=0b00000010;
        write_string(0xc5, "     *");
        delay(5);
        write_string(0xc5, "      ");
        delay(5);
}

void down_loading_bar2(void){
      
      Pim.pth.byte=0;
      

        Pim.pth.byte=0b00000001;
        write_string(0xc5, "*");
        delay(5); 
        Pim.pth.byte=0b00100000;
        write_string(0xc5, " *");
        delay(5);
        Pim.pth.byte=0b00010000;
        write_string(0xc5, "  *");
        delay(5);
        Pim.pth.byte=0b00001000;
        write_string(0xc5, "   *");
        delay(5);
        Pim.pth.byte=0b00000100;
        write_string(0xc5, "    *");
        delay(5);
        Pim.pth.byte=0b00000010;
        write_string(0xc5, "     *");
        delay(5);
        Pim.pth.byte=0b00000001;
        write_string(0xc5, "      *");
        delay(5); 
        Pim.pth.byte=0b00100000;
        write_string(0xc5, "       *");
        delay(5);
        Pim.pth.byte=0b00010000;
        write_string(0xc5, "        *");
        delay(5);
        Pim.pth.byte=0b00001000;
        write_string(0xc5, "         *");
        delay(5);
        Pim.pth.byte=0b00000100;
        write_string(0xc5, "          *");
        delay(5);
        Pim.pth.byte=0b00000010;
        write_string(0xc5, "           *");
        delay(5);
        write_string(0xc5, "            ");
        delay(5);

}


void door(void){
     
     Regs.ddrb.byte = 0xff;             //포트B 출력방향으로 표시 
     Pim.ddrm.byte = 0b11000000; // 포트 M 의 6,7 번 핀을 출력으로 설정
     
     Regs.portb.byte = 0xff;            //모든 LED 소등
     Pim.ptm.byte = 0xff; 
     delay(5);
     Regs.portb.byte = 0b00000000;      //모든 LED 점등 
     Pim.ptm.byte = 0b00111111;      
     delay(5); 
     Regs.portb.byte = 0b00110000;      //모든 LED 점등
     Pim.ptm.byte = 0b00111111; 
     delay(5); 
     Regs.portb.byte = 0b01111000;      //4,5번 LED 소등
     Pim.ptm.byte = 0b00111111;
     delay(5);
     Regs.portb.byte = 0b11111100;      //3,4,5,6번 LED 소등
     Pim.ptm.byte = 0b00111111;
     delay(5);
     Regs.portb.byte = 0b11111110;      //2,3,4,5,6,7번 LED 소등 
     Pim.ptm.byte = 0b01111111;
     delay(5);
     Regs.portb.byte = 0b11111111;      //모든 LED 소등
     Pim.ptm.byte = 0b11111111;
     delay(5); 
     
     Regs.portb.byte = 0b11111111;            //모든 LED 소등
     Pim.ptm.byte = 0b11111111;
     delay(5);
     Regs.portb.byte = 0b11111110;      //2,3,4,5,6,7번 LED 소등
     Pim.ptm.byte = 0b01111111; 
     delay(5); 
     Regs.portb.byte = 0b11111100;      //3,4,5,6번 LED 소등
     Pim.ptm.byte = 0b00111111;
     delay(5); 
     Regs.portb.byte = 0b01111000;      //4,5번 LED 소등
     Pim.ptm.byte = 0b00111111;
     delay(5);
     Regs.portb.byte = 0b00110000;      //모든 LED 점등 
     Pim.ptm.byte = 0b00111111;
     delay(5);
     Regs.portb.byte = 0b00000000;            //모든 LED 소등
     Pim.ptm.byte = 0b00111111;
     delay(5);
     
     Regs.portb.byte = 0xff;            //모든 LED 소등
     Pim.ptm.byte = 0xff;
     delay(5); 
}




void buzzer(void){   //turn on and off buzzer
     
     Regs.ddra.byte = 0xff;

     Regs.porta.byte = 0b01111111;
     delay(1);
     Regs.porta.byte = 0b11111111;
     
     
}



void up(void){                 //motor cw
  
  Pwm.pwmpol.byte = PPOL1 + PPOL2;
  set_pwm(250, 250/2);
 
}


void down(void){               //motor ccw

  Pwm.pwmpol.byte = PPOL0 + PPOL2;
  set_pwm(250, 250/2);
  
  
}

  
void movement(void){

    floor_reservation();
    
    
    if(current_level == reserved_level-48){    //same floor
    
      buzzer(); //activate buzzer
      door();       //opem door
      current_level = reserved_level-48;  //reserved level -> current_level
      load_7segment();                    //print on 7segment
      load_reservation();
    }

    if(current_level == 1 && reserved_level == '2'){   //1->2 floor
      
      Pwm.pwmsdn.bit.pwm7en = 0;
      up();                   //motor clockwise
      up_loading_bar1();
      buzzer();
      Pwm.pwmsdn.bit.pwm7en = 1;
      door();
      current_level = reserved_level-48;
      load_7segment();
      load_reservation();
      
           
    }
    
    if(current_level == 1 && reserved_level == '3'){   //1->3 floor
      
      Pwm.pwmsdn.bit.pwm7en = 0;
      up();
      up_loading_bar2();
      buzzer();
      Pwm.pwmsdn.bit.pwm7en = 1;
      door();
      current_level = reserved_level-48;
      load_7segment();
      load_reservation();
        
    }
    
    if(current_level == 2 && reserved_level == '3'){    //2->3 floor
    
      Pwm.pwmsdn.bit.pwm7en = 0;
      up();
      up_loading_bar1();
      buzzer();
      Pwm.pwmsdn.bit.pwm7en = 1;
      door();
      current_level = reserved_level-48;
      load_7segment();
      load_reservation();
        
    }
   
    if(current_level == 2 && reserved_level == '1'){    //2->1 floor
      Pwm.pwmsdn.bit.pwm7en = 0;
      down();
      down_loading_bar1();
      buzzer();
      Pwm.pwmsdn.bit.pwm7en = 1;
      door();
      current_level = reserved_level-48;
      load_7segment();
      load_reservation();  
    }
   
    if(current_level == 3 && reserved_level == '1'){    //3->1 floor
      
      Pwm.pwmsdn.bit.pwm7en = 0;
      down();
      down_loading_bar2();
      buzzer();
      Pwm.pwmsdn.bit.pwm7en = 1;
      door();
      current_level = reserved_level-48;
      load_7segment();
      load_reservation();
        
    }
    
    if(current_level == 3 && reserved_level == '2'){    //3->2 floor
      
      Pwm.pwmsdn.bit.pwm7en = 0;
      down();
      down_loading_bar1();
      buzzer();
      Pwm.pwmsdn.bit.pwm7en = 1;
      door();
      current_level = reserved_level-48;
      load_7segment();
      load_reservation(); 
    }
}  


void floor_reservation(void){                //take value from switch interrupt
   reserved_level = floor[0];       //place in the first element of array
  
}





void load_reservation(void){
                                        //take all elements down the row

    for(n=0; n<i; n++){               
      floor[n] = floor[n+1];
      
    }
    floor[i-1]=' ';     //dump elements
    
    write_string(0x80, floor); //print the reservation list
    i--;
    
    //move pointer up the array
    
        

}




void delay(unsigned int n) {
  
  unsigned int i;
  
  while(n>0){
    for (i=1; i != 0; i++);      //면서 시간 지연
    n--;
  }
}

