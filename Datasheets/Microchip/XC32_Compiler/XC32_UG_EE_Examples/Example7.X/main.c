/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC32MX470F512L
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC32 1.40
        MPLAB             :  MPLAB X 3.40
   
  Acknowledgments:
    nvm_basic.c source code from nvm_plib_examples.zip
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

#include "mcc_generated_files/mcc.h"

// Program Flash Physical Addresses:  0x1D00_0000 - 0x1D07_FFFF
// Program Flash Virtual Addresses:   KSEG0: 0x9D00_0000 - 0x9D07_FFFF
//                                    KSEG1: 0xBD00_0000 - 0xBD07_FFFF
#define NVM_PROGRAM_PAGE 0xbd008000

unsigned int databuff[128];

/*
                         Main application
 */
int main(void)
{
    unsigned int x;
    
    // initialize the device
    SYSTEM_Initialize();
    
    // Fill databuff with some data
	for(x =0; x < sizeof(databuff); x++)
		databuff[x] = x;

	// Erase second page of Program Flash
	NVM_ErasePage((void *)NVM_PROGRAM_PAGE);

	// Write 128 words starting at Row Address NVM_PROGRAM_PAGE
	NVM_WriteRow((void *)NVM_PROGRAM_PAGE, (void*)databuff);

	// Verify data matches
	if(memcmp(databuff, (void *)NVM_PROGRAM_PAGE, sizeof(databuff)))
	{
		// If not turn led0 on to indicate an error
		IO_RA0_SetHigh();
	}
    
    else {
		// If true turn led2 on to indicate success
		IO_RA2_SetHigh();        
    }
        
    while (1)
    {
            // End of program
    }

    return -1;
}
/**
 End of File
*/