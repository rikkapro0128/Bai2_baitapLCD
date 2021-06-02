
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
#define timeTest 2000 
#include <xc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "lcd.h"

void main(void) {
    const char your_name[] = "Trinh Kieu Oanh";
    const char your_born[] = "NgaySinh:10/2001";
    const char your_live[] = "NoiSinh:Dong Nai";
    const char HKTT[] = "HKTT: Go Vap";
    const char class[] = "Lop: DTVT15A";
    const char MSSV[] = "MSSV:19471301";
    lcd_init();
    lcd_putc('\f');
    lcd_gotoxy(0, 0);
    lcd_puts(your_name);
    lcd_gotoxy(0, 1);
    lcd_puts(MSSV);
    __delay_ms(timeTest);
    lcd_putc('\f');
    lcd_gotoxy(0, 0);
    lcd_puts(your_born);
    lcd_gotoxy(0, 1);
    lcd_puts(your_live);
    __delay_ms(timeTest);
    lcd_putc('\f');
    lcd_gotoxy(0, 0);
    lcd_puts(HKTT);
    lcd_gotoxy(0, 1);
    lcd_puts(class);
    __delay_ms(timeTest);
}
