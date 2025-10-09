#include "IOs.h"
#include "UART2.h"

uint16_t time_elapsed_ms;

void IOinit() 
{
    TRISBbits.TRISB9 = 0;

    TRISAbits.TRISA4 = 1;
    CNPU1bits.CN0PUE = 1;
    CNEN1bits.CN0IE = 1;

    TRISBbits.TRISB4 = 1;
    CNPU1bits.CN1PUE = 1;
    CNEN1bits.CN1IE = 1;

    TRISBbits.TRISB7 = 1;
    CNPU2bits.CN23PUE = 1;
    CNEN2bits.CN23IE = 1;  
}

void IOcheck()
{   // Check combination PB1 + PB2 + PB3 first
    if (PORTBbits.RB7 == 0 && PORTBbits.RB4 == 0 && PORTAbits.RA4 == 0) 
    {
        Disp2String("\033[2J\033[HAll PBs pressed\r");
        while (PORTBbits.RB7 == 0 && PORTBbits.RB4 == 0 && PORTAbits.RA4 == 0)
            _LATB9 = 1;
    }
    else if (PORTBbits.RB7 == 0 && PORTAbits.RA4 == 0)
    {
        Disp2String("\033[2J\033[HPB1 and PB3 event\r");
        while (PORTBbits.RB7 == 0 && PORTAbits.RA4 == 0)
        {
            _LATB9 ^= 1;   // Blink LED while both buttons are pressed
            delay_ms(500);
        }
    }
    else if (PORTBbits.RB4 == 0 && PORTAbits.RA4 == 0) 
    {
        Disp2String("\033[2J\033[HPB2 and PB3 event\r");
        while (PORTBbits.RB4 == 0 && PORTAbits.RA4 == 0)
            _LATB9 = 1;
    }
    else if (PORTBbits.RB7 == 0 && PORTBbits.RB4 == 0) 
    {
        Disp2String("\033[2J\033[HPB1 and PB2 event\r");
        while (PORTBbits.RB7 == 0 && PORTBbits.RB4 == 0)
            _LATB9 = 1;
    }
    else if (PORTBbits.RB7 == 0) 
    {
        Disp2String("\033[2J\033[HPB1 event\r");
        while (PORTBbits.RB7 == 0)
        {
            _LATB9 ^= 1;
            delay_ms(250);
        }
    }
    else if (PORTBbits.RB4 == 0) 
    {
        Disp2String("\033[2J\033[HPB2 event\r");
        while (PORTBbits.RB4 == 0)
        {
            _LATB9 ^= 1;
            delay_ms(1000);
        }
    }
    else if (PORTAbits.RA4 == 0) 
    {
        Disp2String("\033[2J\033[HPB3 event\r");
        while (PORTAbits.RA4 == 0)
        {
            _LATB9 ^= 1;
            delay_ms(3000);
        }
    }
    else
    {
        Disp2String("\033[2J\033[HNothing pressed\r");
    }
}
