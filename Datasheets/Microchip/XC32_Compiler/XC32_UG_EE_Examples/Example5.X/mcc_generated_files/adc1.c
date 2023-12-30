
/**
  ADC1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adc1.c

  @Summary
    This is the generated header file for the ADC1 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides APIs for driver for ADC1.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC32MX470F512L
        Driver Version    :  0.5
    The generated drivers are tested against the following:
        Compiler          :  XC32 1.40
        MPLAB 	          :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "adc1.h"

/**
  Section: Driver Interface
*/

void ADC1_Initialize (void)
{
    // ASAM enabled; DONE disabled; CLRASAM disabled; FORM Integer 16 bit; SAMP disabled; SSRC Internal counter; SIDL disabled; ON enabled; 
   AD1CON1 = 0x80E4;

    // CSCNA enabled; ALTS disabled; BUFM disabled; SMPI 1; OFFCAL disabled; VCFG AVDD/AVSS; 
   AD1CON2 = 0x400;

    // SAMC 8; ADRC PBCLK; ADCS 0; 
   AD1CON3 = 0x800;

    // CH0SA AN0; CH0SB AN0; CH0NB Vrefl; CH0NA Vrefl; 
   AD1CHS = 0x0;

    // CSSL26 disabled; CSSL25 disabled; CSSL28 disabled; CSSL27 disabled; CSSL22 disabled; CSSL21 disabled; CSSL24 disabled; CSSL9 disabled; CSSL23 disabled; CSSL20 disabled; CSSL0 disabled; CSSL8 disabled; CSSL7 disabled; CSSL6 disabled; CSSL5 disabled; CSSL4 disabled; CSSL3 disabled; CSSL29 disabled; CSSL2 enabled; CSSL1 disabled; CSSL15 disabled; CSSL14 disabled; CSSL17 disabled; CSSL16 disabled; CSSL11 disabled; CSSL10 disabled; CSSL13 disabled; CSSL12 disabled; CSSL30 disabled; CSSL19 disabled; CSSL18 disabled; 
   AD1CSSL = 0x4;


}

void ADC1_Start(void)
{
   AD1CON1bits.SAMP = 1;
}

void ADC1_Stop(void)
{
   AD1CON1bits.SAMP = 0;
}

void ADC1_ConversionResultBufferGet(uint32_t *buffer)
{
    int count;
    uint32_t *ADC32Ptr;

    ADC32Ptr = (uint32_t *)&(ADC1BUF0);
    
    for(count=0; count<=1; count++)
    {
        buffer[count] = (uint32_t)*ADC32Ptr;
        ADC32Ptr = ADC32Ptr + 4;
    }
}

uint32_t ADC1_ConversionResultGet(void)
{
    return ADC1BUF0;
}

bool ADC1_IsConversionComplete( void )
{
    return AD1CON1bits.DONE; //Wait for conversion to complete   
}

void ADC1_ChannelSelect( ADC1_CHANNEL channel )
{
    AD1CHS = channel << 16;
}

void ADC1_Tasks ( void )
{
    if(IFS0bits.AD1IF)
    {
        // Read ADC Buffer since the interrupt is persistent
    
        // clear ADC interrupt flag
        IFS0CLR= 1 << _IFS0_AD1IF_POSITION;
    }
}

/**
  End of File
*/
