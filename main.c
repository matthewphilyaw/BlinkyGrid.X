#define _XTAL_FREQ 16000000

#include <xc.h>
#include <limits.h>
#include <pic16f1823.h>
#include "configbits.h"
#include "led_driver.h"

const char message[] = { 255, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5, 2, 3, 3, 3, 4, 3, 5, 3, 6, 1, 6, 2, 6, 3, 6, 4, 6, 5, 255, 1, 2, 1, 4, 2, 1, 2, 3, 2, 5, 3, 0, 3, 6, 4, 1, 4, 5, 5, 2, 5, 4, 6, 3, 255, 1, 1, 1, 5, 2, 1, 2, 5, 3, 1, 3, 5, 4, 1, 4, 5, 5, 1, 5, 5, 6, 2, 6, 3, 6, 4, 255 };

void main() {
    // Setting configuration and clearing ports.
    OSCCON = 0x78;
    ANSELA = 0x0;
    ANSELC = 0x0;
    PORTC = 0x0;
    PORTA = 0x0;
    TRISC = 0xff;
    TRISA = 0xff;

    unsigned int advance = 0;
    unsigned int total = sizeof(message)/sizeof(char);
    while (1)
    {
        if (advance + 1 >= total)
        {
            advance = 0;
            TRISA = 0xff;
            TRISC = 0xff;
        }

        if (message[advance] == 0xff)
        {
            unsigned int count = 250;
            while (count-- > 1)
            {
                unsigned int i = advance + 1;
                while (1)
                {
                    display_led(&message[i], &message[i+1]);
                    __delay_us(500);
                    i+=2;
                    if (message[i] >= 255 || (i + 1) >= total)
                        break;
                }
            }
            advance++;
        }

        // Hold for x number of seconds...
                // Transition
        unsigned int count = 50;
        while (count-- > 1)
        {
            unsigned int i = advance;
            while (1)
            {
                display_led(&message[i], &message[i+1]);
                __delay_us(500);
                i+=2;
                if (message[i] >= 255 || (i + 1) >= total)
                    break;
            }

        }
        advance += 2;

        if (message[advance] >= 255)
        {
            TRISA = 0xff;
            TRISC = 0xff;
            __delay_ms(500);
        }
    }
}
