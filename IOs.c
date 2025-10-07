#include "IOs.h"
#include "UART2.h"

uint16_t time_elapsed_ms;

void IOinit() {
    TRISBbits.TRISB9 = 0;
    LATBbits.LATB9 = 1;
    
//    TRISAbits.TRISA6 = 0;
//    LATAbits.LATA6 = 1;
    
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

int IOcheck()
{
    if (PORTBbits.RB4 == 0 && PORTAbits.RA4 == 0) 
    {
        Disp2String("PB2 and PB3 event\n\r");
        while (PORTBbits.RB4 == 0 && PORTAbits.RA4 == 0)
            _LATB9 = 1;
        return 1;
    }
    else if (PORTBbits.RB7 == 0) 
    {
        Disp2String("PB1 event\n\r");
        while (PORTBbits.RB7 == 0)
        {
            _LATB9 ^= 1;
            delay_ms(250);
        }
    }
    else if (PORTBbits.RB4 == 0) 
    {
        Disp2String("PB2 event\n\r");
        while (PORTBbits.RB4 == 0)
        {
            _LATB9 ^= 1;
            delay_ms(1000);
        }
    }
    else if (PORTAbits.RA4 == 0) 
    {
        Disp2String("PB3 event\n\r");
        while (PORTAbits.RA4 == 0)
        {
            _LATB9 ^= 1;
            delay_ms(3000);
        }
    }
    return 0;
}
