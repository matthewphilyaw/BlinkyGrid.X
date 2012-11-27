#include "led_driver.h"
#include <pic16f1823.h>

void display_led(char* x, char* y)
{
    set_led(&grid[*x][*y]);
}

void set_led(char* pair) {
    char flip = *pair & 0x80;
    char lo = 0x01 << (0x0f & (*pair ^ 0x80));
    char hi = 0x01 << ((*pair & 0x70) >> 4);
    char mask = (hi | lo) ^ 0xff;
    TRISA = mask >> 6;
    TRISC = mask;

    if (flip == 0x00)
    {
        PORTA = hi >> 6;
        PORTC = hi;
    }
    else
    {
        PORTA = lo >> 6;
        PORTC = lo;
    }
}
