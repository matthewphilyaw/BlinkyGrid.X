/* 
 * File:   led_driver.h
 * Author: matth_000
 *
 * Created on November 19, 2012, 6:47 AM
 */

#ifndef LED_DRIVER_H
#define	LED_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef unsigned char u_char;
    void parse_byte(unsigned char LedByte);
    void set_led(u_char*);

#ifdef	__cplusplus
}
#endif

#endif	/* LED_DRIVER_H */

