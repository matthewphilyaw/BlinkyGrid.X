#define _XTAL_FREQ 16000000

#include <xc.h>
#include <pic16f1823.h>
#include "configbits.h"
#include "led_driver.h"

#define DEL 200
typedef unsigned char u_char;
static u_char message[] = { 0x93, 0xa6, 0x06, 0x23, 0x37, 0x82, 0xd6, 0x07, 0x45, 0x95, 0xb4, 0x25 };
//0000 0000
//1000 0001

void main() {
    OSCCON = 0x78;
    ANSELA = 0x0;
    ANSELC = 0x0;
    PORTC = 0x0;
    PORTA = 0x0;
    TRISC = 0x0;
    TRISA = 0x0;
    TRISA = 0xff;

    while (1)
    {
        for (u_char i = 0; i < sizeof(message)/sizeof(u_char); i++)
        {
            set_led(&message[i]);
            __delay_us(750);
        }
    }
}

/*u_char rows = 0x07;
        u_char count = 2 * rows;
        for (u_char i = 0; i < rows; i++)
        {
            set_bank(i, i+1, count);
            count -= 2;
        }
 *
 * void set_bank(u_char row, u_char start, u_char count)
{
    for (u_char i = 0; i < count; i++)
    {
        flip = !flip;
        set_led(row << 4 | start);
        if (i % 2 && i > 0) start++;
        __delay_ms(DEL);
    }
}*/

//      HI   Lo
// byte 0000 0000
/*void set_led(u_char pair) {
    u_char lo = 0x01 << (0x0f & pair);
    u_char hi = 0x01 << (pair >> 4);
    u_char mask = (hi | lo) ^ 0xff;
    TRISA = mask >> 6;
    TRISC = mask;

    if (!flip)
    {
        PORTA = hi >> 6;
        PORTC = hi;
    }
    else
    {
        PORTA = lo >> 6;
        PORTC = lo;
    }
}*/

