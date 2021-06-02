
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#define _XTAL_FREQ 4000000
#include <xc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "lcd.h"

void main(void) {
    while(1) {
        lcd_init();
        lcd_puts("\fNguyen Tan Phap\nMSSV: 19436481"); // x�a m�n h�nh
        __delay_ms(2000);
        lcd_puts("\fNgaySinh:12/2001\nNS: NinhThuan"); // x�a m�n h�nh
        __delay_ms(2000);
        lcd_puts("\fHKTT:GoVap,TPHCM\nLop:DHVT15A"); // x�a m�n h�nh
        __delay_ms(2000);
    }
}
