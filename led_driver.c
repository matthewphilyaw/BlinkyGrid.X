#include "led_driver.h"
#include <pic16f1823.h>

void set_led(u_char* pair) {
    u_char flip = *pair & 0x80;
    u_char lo = 0x01 << (0x0f & (*pair ^ 0x80));
    u_char hi = 0x01 << ((*pair & 0x70) >> 4);
    u_char mask = (hi | lo) ^ 0xff;
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
