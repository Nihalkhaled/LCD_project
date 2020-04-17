/*
 * File:   main.c
 * Author: Hossam Eldeen Altokhy
 *
 * Created on April 4, 2020, 6:24 PM
 */
#define F_CPU 16000000UL


#include <avr/io.h>
#include <util/delay.h>
#include "Config.h"
#include "DIO.h"
#include "lcd.h"







int i = 0;

char x_2[] = "LED2 is ON";
char y_2[] = "LED2 is OFF";

char x_1[] = "LED1 is ON";
char y_1[] = "LED1 is OFF";

char x_0[] = "LED0 is ON";
char y_0[] = "LED0 is OFF";

char flag = 0;

int main(void) {

    LCD_Init();//lcd connected with controller

      resetPIN(Buzzer, portA); // Turn Buzzer OFF
 //   LCD_Char('A');
      PINDas(BUTTON2, IN);
      PINBas(BUTTON0,IN);
      PINBas(BUTTON1,IN);
      
      PINCas(LED0, OUT);
      PINCas(LED1, OUT); 
      PINDas(LED2, OUT);
      
      resetPIN(LED2, portD); // LED2 init OFF
      resetPIN(LED0, portC);
      resetPIN(LED1, portC);
      
      //LCD_String(y);//it takes a pointer to character
      while (1) {
        if (isPressedD(BUTTON2)) {
            flag ^= 1;
            togglePIND(LED2);

            if (flag) {
                LCD_Clear();
                LCD_String(x_2);
            } else {
                LCD_Clear();
                LCD_String(y_2);
            }
            _delay_ms(500);}
        
        if (isPressedB(BUTTON0)) {
            flag ^= 1;
            togglePINC(LED0);

            if (flag) {
                LCD_Clear();
                LCD_String(x_0);
            } else {
                LCD_Clear();
                LCD_String(y_0);
            }
            _delay_ms(500);}
        
       
        if (isPressedB(BUTTON1)) {
            flag ^= 1;
            togglePINC(LED1);

            if (flag) {
                LCD_Clear();
                LCD_String(x_1);
            } else {
                LCD_Clear();
                LCD_String(y_1);
            }
            _delay_ms(500);
        }

    }

            
            
           
}
 
