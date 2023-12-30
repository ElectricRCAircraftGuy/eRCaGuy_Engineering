/*
 * File:   example3.c
 * Author: Microchip Technology
 *
 * Created on January 4, 2017, 1:55 PM
 */

/******************************************************************************
 * Software License Agreement
 *
 * Copyright � 2017 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED ìAS ISî WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
 * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
 * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
 * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
 * OR OTHER SIMILAR COSTS.
 *
 *****************************************************************************/

// PIC32MX470F512L Configuration Bit Settings
// 'C' source line config statements
// DEVCFG3
// USERID = No Setting
#pragma config FSRSSEL = PRIORITY_7     // Shadow Register Set Priority Select (SRS Priority 7)
#pragma config PMDL1WAY = ON            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
#pragma config FUSBIDIO = ON            // USB USID Selection (Controlled by Port Function)
#pragma config FVBUSONIO = ON           // USB VBUS ON Selection (Controlled by Port Function)

// DEVCFG2
#pragma config FPLLIDIV = DIV_12        // PLL Input Divider (12x Divider)
#pragma config FPLLMUL = MUL_24         // PLL Multiplier (24x Multiplier)
#pragma config UPLLIDIV = DIV_12        // USB PLL Input Divider (12x Divider)
#pragma config UPLLEN = OFF             // USB PLL Enable (Disabled and Bypassed)
#pragma config FPLLODIV = DIV_256       // System PLL Output Clock Divider (PLL Divide by 256)

// DEVCFG1
#pragma config FNOSC = FRCDIV           // Oscillator Selection Bits (Fast RC Osc w/Div-by-N (FRCDIV))
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enabled)
#pragma config IESO = OFF               // Internal/External Switch Over (Disabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FPBDIV = DIV_8           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/8)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable (Watchdog Timer is in Non-Window Mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled (SWDTEN Bit Controls))
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window Size is 25%)

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is Disabled)
#pragma config JTAGEN = OFF             // JTAG Enable (JTAG Disabled)
#pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (Communicate on PGEC2/PGED2)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <cp0defs.h>
#include <sys/attribs.h>

// CORE_TICK_RATE = FOSC/2/TOGGLES_PER_SEC
// FOSC/2 = Core timer clock frequency = 8MHz/2=4MHz
// TOGGLES_PER_SEC = Toggle LED x times per second; x=5
#define CORE_TICK_RATE          800000u

// Interrupt function for Core Timer (CT)
void __ISR(_CORE_TIMER_VECTOR, IPL2SOFT) CTInterruptHandler(void)
{
    // static variable for permanent storage duration
    static unsigned char portValue = 0;
    // variables for Compare period
    unsigned long ct_count = _CP0_GET_COUNT();
    unsigned long period = CORE_TICK_RATE;
    
    // write to port latch
    LATA = portValue++;

    // update the Compare period
    period += ct_count;
    _CP0_SET_COMPARE(period);

    // clear the interrupt flag
    IFS0CLR = _IFS0_CTIF_MASK;
}

int main (void)
{
    unsigned int stat_gie, cause_val;

    // Disables interrupts by clearing the global interrupt enable bit
    // in the STATUS register.
    stat_gie = __builtin_disable_interrupts();

    // Port A access
    TRISA = 0x0; // set all port bits to be output
    LATA = 0x0;  // clear all bits

    // Configure the core timer
	// clear the CP0 Count register
    _CP0_SET_COUNT(0);
    // set up the period in the CP0 Compare register
    _CP0_SET_COMPARE(CORE_TICK_RATE);
    // halt core timer and program at a debug breakpoint
    _CP0_BIC_DEBUG(_CP0_DEBUG_COUNTDM_MASK);

    // Set up core timer interrupt
    // clear core timer interrupt flag
    IFS0CLR = _IFS0_CTIF_MASK;
    // set core time interrupt priority of 2
    IPC0CLR = _IPC0_CTIP_MASK;
    IPC0SET = (2 << _IPC0_CTIP_POSITION);
    // set core time interrupt subpriority of 0
    IPC0CLR = _IPC0_CTIS_MASK; 
    IPC0SET = (0 << _IPC0_CTIS_POSITION);
    // enable core timer interrupt
    IEC0CLR = _IEC0_CTIE_MASK;
    IEC0SET = (1 << _IEC0_CTIE_POSITION);
    
    // set the CP0 Cause register Interrupt Vector bit
    cause_val = _CP0_GET_CAUSE();
    cause_val |= _CP0_CAUSE_IV_MASK;
    _CP0_SET_CAUSE(cause_val);
      
    // enable multi-vector interrupts
    INTCONSET = _INTCON_MVEC_MASK;
    
    // enable global interrupts
    __builtin_enable_interrupts();

    while(1);

    return -1;
}
