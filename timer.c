#include "timer.h"

void timerInit()
{
    // TMR2 config
    T2CONbits.T32 = 0; // operate timer 2 as 16 bit timer
    T2CONbits.TCKPS = 3;
    T2CONbits.TCS = 0;
    T2CONbits.TGATE = 0;
    T2CONbits.TSIDL = 0;
    IPC1bits.T2IP = 2;
    IFS0bits.T2IF = 0;
    IEC0bits.T2IE = 1;

    //TMR3 config
    T3CONbits.TCKPS = 1; // set prescaler to 1:8
    T3CONbits.TCS = 0; // use internal clock
    T3CONbits.TSIDL = 0; //operate in idle mode
    IPC2bits.T3IP = 2; //7 is highest and 1 is lowest pri.
    IFS0bits.T3IF = 0;
    IEC0bits.T3IE = 1; //enable timer interrupt
    PR3 = 15625 * 2; // set the count value for 0.5 s (or 500 ms)
    TMR3 = 0;
    T3CONbits.TON = 0;
}

void delay_ms(uint16_t time_ms) {
    PR2 = 1 * time_ms;
    TMR2 = 0;
    
    T2CONbits.TON = 1;
    
    Idle();
    
    return;
}
