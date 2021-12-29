
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

  // �������� 7segment �� ǥ�� 
void load_7segment(void){
  
    
    if(reserved_level==49){          //����� ���� 1���̸� 
       set_7segment(1);             //7segment�� 1���� ǥ�� 
                 //����Ǿ��ִ� �迭���� ��ĭ�� �����(ù��° �迭�� �ִ� ���� load�Ǽ�)
                 //�������� 1������ �ȴ�.
    }
    if(reserved_level==50){          //����� ���� 2���̸� 
       set_7segment(2);             //7segment�� 2���� ǥ��
                //����Ǿ��ִ� �迭���� ��ĭ�� �����(ù��° �迭�� �ִ� ���� load�Ǽ�)
                 //�������� 2������ �ȴ�.
    }                               
    if(reserved_level==51){          //����� ���� 3���̸�
       set_7segment(3);             //7segment�� 3���� ǥ�� 
                 //����Ǿ��ִ� �迭���� ��ĭ�� �����(ù��° �迭�� �ִ� ���� load�Ǽ�)
                  //�������� 3������ �ȴ�.
    }
    
    
 //  }
}


  // ��½��� �ð�������� loadingbar ���� 
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
     
     Regs.ddrb.byte = 0xff;             //��ƮB ��¹������� ǥ�� 
     Pim.ddrm.byte = 0b11000000; // ��Ʈ M �� 6,7 �� ���� ������� ����
     
     Regs.portb.byte = 0xff;            //��� LED �ҵ�
     Pim.ptm.byte = 0xff; 
     delay(5);
     Regs.portb.byte = 0b00000000;      //��� LED ���� 
     Pim.ptm.byte = 0b00111111;      
     delay(5); 
     Regs.portb.byte = 0b00110000;      //��� LED ����
     Pim.ptm.byte = 0b00111111; 
     delay(5); 
     Regs.portb.byte = 0b01111000;      //4,5�� LED �ҵ�
     Pim.ptm.byte = 0b00111111;
     delay(5);
     Regs.portb.byte = 0b11111100;      //3,4,5,6�� LED �ҵ�
     Pim.ptm.byte = 0b00111111;
     delay(5);
     Regs.portb.byte = 0b11111110;      //2,3,4,5,6,7�� LED �ҵ� 
     Pim.ptm.byte = 0b01111111;
     delay(5);
     Regs.portb.byte = 0b11111111;      //��� LED �ҵ�
     Pim.ptm.byte = 0b11111111;
     delay(5); 
     
     Regs.portb.byte = 0b11111111;            //��� LED �ҵ�
     Pim.ptm.byte = 0b11111111;
     delay(5);
     Regs.portb.byte = 0b11111110;      //2,3,4,5,6,7�� LED �ҵ�
     Pim.ptm.byte = 0b01111111; 
     delay(5); 
     Regs.portb.byte = 0b11111100;      //3,4,5,6�� LED �ҵ�
     Pim.ptm.byte = 0b00111111;
     delay(5); 
     Regs.portb.byte = 0b01111000;      //4,5�� LED �ҵ�
     Pim.ptm.byte = 0b00111111;
     delay(5);
     Regs.portb.byte = 0b00110000;      //��� LED ���� 
     Pim.ptm.byte = 0b00111111;
     delay(5);
     Regs.portb.byte = 0b00000000;            //��� LED �ҵ�
     Pim.ptm.byte = 0b00111111;
     delay(5);
     
     Regs.portb.byte = 0xff;            //��� LED �ҵ�
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
    for (i=1; i != 0; i++);      //�鼭 �ð� ����
    n--;
  }
}

