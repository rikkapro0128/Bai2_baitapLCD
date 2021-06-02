
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
    const char dat_line1[] = {'N','g','u','y',0X01,'n','T',0X01,'n','P', 'h', 0X02, 'p'};
    const char dat_line2[] = {'N','g',0X03,'y','S','i','n','h', ':', '1', '2', '/', '2', '0', '0', '1'};
    const char dat_line3[] = {'N',0x05,'i','S', ':', 'N', 'i', 'n', 'h', 'T', 'h', 'u', 0x04, 'n'};
    const char dat_line4[] = {'L', 0x06, 'p', ':', 0x00, 'H', 'V', 'T', '1', '5', 'A'};
    const char dat_line5[] = {'H','K','T','T', ':', 'G', 0x07, 'V', 0x09, 'p'};
    const char MSSV[] = "MSSV:19436481";
    unsigned int times = 3;
    const char cgram_dat[] = {11, 20, 12, 18, 12, 20, 24, 14, // e nguyen 0
                1, 10, 20, 0, 28, 20, 30, 0 , // a tan1
            2, 4, 8, 0, 28, 20, 30, 0 , // a sac 2
            0, 8, 4, 0, 28, 20, 30, 0 , // a ngay  3
    8, 20, 0, 28, 20, 30, 8, 0, // a thuan 4
    0, 12, 4, 28, 20, 20, 28, 0 , // o noi sinh  5
    1, 2, 12, 4, 28, 20, 28, 0 , // o lop  6
    16, 8, 0, 28, 20, 20, 28, 0, // 7
    0x0E,0X09,0X09,0X1D,0X09,0X09,0X0E,0X00, //8
    1, 10, 20, 0, 28, 20, 30, 0, // 9 
            0X99}; // Ma ket thuc chuoi la 99H
    unsigned char i;
    lcd_init(); // Khoi dong LCD
    // Xu ly nap ma ky tu dac biet vao CGRAM.
    i = 0;
    lcd_put_byte(0,0x40); // Lenh = 40H - Dat CGRAM co dia chi bat dau la 00H. while(lcd_busy()); // Kiem tra LCD bao ban. while(cgram_dat[i]!=0x99) // Kiem tra nap xong du lieu cho cac ky tu dac biet, { // ky tu ket thuc chuoi la 99H.
    while(lcd_busy());
    while(cgram_dat[i] != 0x99){
        lcd_put_byte(1,cgram_dat[i]); // Ghi cac ma ky tu dac biet vao CGRAM theo dia chi. while(lcd_busy()); // Kiem tra LCD bao ban.
        while(lcd_busy());
        i++;
    }
    while(times--) {
        lcd_putc('\f'); // xóa màn hình
        __delay_ms(500);
        lcd_gotoxy(0,0); // Xac dinh toa do bat dau hien thi cho hang 1.
        for(i = 0; i <= 12; i++) {
            lcd_putc(dat_line1[i]);
        }
        lcd_gotoxy(0,1); // Xac dinh toa do bat dau hien thi cho hang 2. for(i=0;i<=9;i++)
        lcd_puts(MSSV);
        __delay_ms(500);
    }
    lcd_putc('\f');
    lcd_gotoxy(0,0);
     // Xac dinh toa do bat dau hien thi cho hang 1.
    for(i = 0; i <= 15; i++) {
        lcd_putc(dat_line2[i]);
    }
    lcd_gotoxy(0,1); // Xac dinh toa do bat dau hien thi cho hang 2. for(i=0;i<=9;i++)
    for(i = 0; i <= 13; i++) {
        lcd_putc(dat_line3[i]);
    }
    lcd_MoveRight(16);
    lcd_putc('\f');
    lcd_gotoxy(0,0);
     // Xac dinh toa do bat dau hien thi cho hang 1.
    for(i = 0; i <= 9; i++) {
        lcd_putc(dat_line5[i]);
    }
    lcd_gotoxy(0,1); // Xac dinh toa do bat dau hien thi cho hang 2. for(i=0;i<=9;i++)
    for(i = 0; i <= 10; i++) {
        lcd_putc(dat_line4[i]);
    }
    lcd_MoveLeft(11);
}
