// INSTRUCTION CODE
#include "lcd.h"


void init_LCD(void)
{
    Regs.ddra.byte = 0x7F;  // ��Ʈ A�� 0~6�� ���� ������ ������� ����
    // ������ ���� 4��Ʈ, 2�� ǥ�� ����
    set_inst_register(CODE_FUNC_SET(0, 1, 0));
    // ���÷��� ǥ��, Ŀ�� �� Ŀ���� ������ ����
    set_inst_register(CODE_DISP_CTRL(1, 0, 0));
    // Ŀ���� �̵�����, ȭ�� �̵� ����    
    set_inst_register(CODE_ENTRY_MODE_SET(0, 0));
    // Clear Display
    set_inst_register(CODE_CLR_DISP);
}

// IR �������Ϳ� ���� �����Ͽ� LCD�� ����� ����
void set_inst_register(BYTE code)
{
    // ��� �ڵ��� ���� 4��Ʈ�� ����
    // ��Ʈ A�� 8��° ��Ʈ�� �ٲ��� ���� (LCD���� ������ ����)
    Regs.porta.byte = ((code&0xF0)>>1)|0x04|(Regs.porta.byte&0x80);
    DISABLE_LCD();
    // ��� �ڵ��� ���� 4��Ʈ�� ����
    Regs.porta.byte = ((code&0x0F)<<3)|0x04|(Regs.porta.byte&0x80);
    DISABLE_LCD();
    ms_delay(1);
}

// LCD�� RAM�� �����͸� ��
void write_data(BYTE data)
{
    // �������� ���� 4��Ʈ�� ����
    Regs.porta.byte = ((data&0xF0)>>1)|0x01|0x04|(Regs.porta.byte&0x80);
    DISABLE_LCD();
    // �������� ���� 4��Ʈ�� ����
    Regs.porta.byte = ((data&0x0F)<<3)|0x01|0x04|(Regs.porta.byte&0x80);
    DISABLE_LCD();
    ms_delay(1);
}

// LCD�� Ư�� ��ġ�� ���ڿ��� ��
void write_string(BYTE offset, char *str)      //offset is the location of LCD, string is the output string
{   
    int i;
    // ���ڿ��� �� �ּ� ����
    set_inst_register(CODE_SET_DDRAM_ADDR(offset));
    for (i = 0; str[i] != '\0'; i++) {
        write_data(str[i]);
    }
}

// ms ������ �ð��� ������Ű�� �Լ�
void ms_delay(unsigned int ms) 
{
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j=0; j < 2650; j++);     // �ƹ��͵� ���� �����鼭 �ð� ����
    }
}