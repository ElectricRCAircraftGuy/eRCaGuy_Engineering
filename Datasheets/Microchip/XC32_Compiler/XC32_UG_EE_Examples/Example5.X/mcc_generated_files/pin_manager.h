/**
  System Interrupts Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the MPLAB(c) Code Configurator device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for MPLAB(c) Code Configurator interrupts.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC32MX470F512L
        Version           :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC32 1.40
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>
/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RA0, high using LATAbits.LATA0.

  @Description
    Sets the GPIO pin, RA0, high using LATAbits.LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA0 high (1)
    IO_RA0_SetHigh();
    </code>

*/
#define IO_RA0_SetHigh()          LATAbits.LATA0 = 1
/**
  @Summary
    Sets the GPIO pin, RA0, low using LATAbits.LATA0.

  @Description
    Sets the GPIO pin, RA0, low using LATAbits.LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA0 low (0)
    IO_RA0_SetLow();
    </code>

*/
#define IO_RA0_SetLow()           LATAbits.LATA0 = 0
/**
  @Summary
    Toggles the GPIO pin, RA0, using LATAbits.LATA0.

  @Description
    Toggles the GPIO pin, RA0, using LATAbits.LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA0
    IO_RA0_Toggle();
    </code>

*/
#define IO_RA0_Toggle()           LATAbits.LATA0 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA0.

  @Description
    Reads the value of the GPIO pin, RA0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA0
    postValue = IO_RA0_GetValue();
    </code>

*/
#define IO_RA0_GetValue()         PORTAbits.RA0
/**
  @Summary
    Configures the GPIO pin, RA0, as an input.

  @Description
    Configures the GPIO pin, RA0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA0 as an input
    IO_RA0_SetDigitalInput();
    </code>

*/
#define IO_RA0_SetDigitalInput()  TRISAbits.TRISA0 = 1
/**
  @Summary
    Configures the GPIO pin, RA0, as an output.

  @Description
    Configures the GPIO pin, RA0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA0 as an output
    IO_RA0_SetDigitalOutput();
    </code>

*/
#define IO_RA0_SetDigitalOutput() TRISAbits.TRISA0 = 0
/**
  @Summary
    Sets the GPIO pin, RA1, high using LATAbits.LATA1.

  @Description
    Sets the GPIO pin, RA1, high using LATAbits.LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA1 high (1)
    IO_RA1_SetHigh();
    </code>

*/
#define IO_RA1_SetHigh()          LATAbits.LATA1 = 1
/**
  @Summary
    Sets the GPIO pin, RA1, low using LATAbits.LATA1.

  @Description
    Sets the GPIO pin, RA1, low using LATAbits.LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA1 low (0)
    IO_RA1_SetLow();
    </code>

*/
#define IO_RA1_SetLow()           LATAbits.LATA1 = 0
/**
  @Summary
    Toggles the GPIO pin, RA1, using LATAbits.LATA1.

  @Description
    Toggles the GPIO pin, RA1, using LATAbits.LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA1
    IO_RA1_Toggle();
    </code>

*/
#define IO_RA1_Toggle()           LATAbits.LATA1 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA1.

  @Description
    Reads the value of the GPIO pin, RA1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA1
    postValue = IO_RA1_GetValue();
    </code>

*/
#define IO_RA1_GetValue()         PORTAbits.RA1
/**
  @Summary
    Configures the GPIO pin, RA1, as an input.

  @Description
    Configures the GPIO pin, RA1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA1 as an input
    IO_RA1_SetDigitalInput();
    </code>

*/
#define IO_RA1_SetDigitalInput()  TRISAbits.TRISA1 = 1
/**
  @Summary
    Configures the GPIO pin, RA1, as an output.

  @Description
    Configures the GPIO pin, RA1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA1 as an output
    IO_RA1_SetDigitalOutput();
    </code>

*/
#define IO_RA1_SetDigitalOutput() TRISAbits.TRISA1 = 0
/**
  @Summary
    Sets the GPIO pin, RA2, high using LATAbits.LATA2.

  @Description
    Sets the GPIO pin, RA2, high using LATAbits.LATA2.

  @Preconditions
    The RA2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA2 high (1)
    IO_RA2_SetHigh();
    </code>

*/
#define IO_RA2_SetHigh()          LATAbits.LATA2 = 1
/**
  @Summary
    Sets the GPIO pin, RA2, low using LATAbits.LATA2.

  @Description
    Sets the GPIO pin, RA2, low using LATAbits.LATA2.

  @Preconditions
    The RA2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA2 low (0)
    IO_RA2_SetLow();
    </code>

*/
#define IO_RA2_SetLow()           LATAbits.LATA2 = 0
/**
  @Summary
    Toggles the GPIO pin, RA2, using LATAbits.LATA2.

  @Description
    Toggles the GPIO pin, RA2, using LATAbits.LATA2.

  @Preconditions
    The RA2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA2
    IO_RA2_Toggle();
    </code>

*/
#define IO_RA2_Toggle()           LATAbits.LATA2 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA2.

  @Description
    Reads the value of the GPIO pin, RA2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA2
    postValue = IO_RA2_GetValue();
    </code>

*/
#define IO_RA2_GetValue()         PORTAbits.RA2
/**
  @Summary
    Configures the GPIO pin, RA2, as an input.

  @Description
    Configures the GPIO pin, RA2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA2 as an input
    IO_RA2_SetDigitalInput();
    </code>

*/
#define IO_RA2_SetDigitalInput()  TRISAbits.TRISA2 = 1
/**
  @Summary
    Configures the GPIO pin, RA2, as an output.

  @Description
    Configures the GPIO pin, RA2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA2 as an output
    IO_RA2_SetDigitalOutput();
    </code>

*/
#define IO_RA2_SetDigitalOutput() TRISAbits.TRISA2 = 0
/**
  @Summary
    Sets the GPIO pin, RA3, high using LATAbits.LATA3.

  @Description
    Sets the GPIO pin, RA3, high using LATAbits.LATA3.

  @Preconditions
    The RA3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA3 high (1)
    IO_RA3_SetHigh();
    </code>

*/
#define IO_RA3_SetHigh()          LATAbits.LATA3 = 1
/**
  @Summary
    Sets the GPIO pin, RA3, low using LATAbits.LATA3.

  @Description
    Sets the GPIO pin, RA3, low using LATAbits.LATA3.

  @Preconditions
    The RA3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA3 low (0)
    IO_RA3_SetLow();
    </code>

*/
#define IO_RA3_SetLow()           LATAbits.LATA3 = 0
/**
  @Summary
    Toggles the GPIO pin, RA3, using LATAbits.LATA3.

  @Description
    Toggles the GPIO pin, RA3, using LATAbits.LATA3.

  @Preconditions
    The RA3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA3
    IO_RA3_Toggle();
    </code>

*/
#define IO_RA3_Toggle()           LATAbits.LATA3 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA3.

  @Description
    Reads the value of the GPIO pin, RA3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA3
    postValue = IO_RA3_GetValue();
    </code>

*/
#define IO_RA3_GetValue()         PORTAbits.RA3
/**
  @Summary
    Configures the GPIO pin, RA3, as an input.

  @Description
    Configures the GPIO pin, RA3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA3 as an input
    IO_RA3_SetDigitalInput();
    </code>

*/
#define IO_RA3_SetDigitalInput()  TRISAbits.TRISA3 = 1
/**
  @Summary
    Configures the GPIO pin, RA3, as an output.

  @Description
    Configures the GPIO pin, RA3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA3 as an output
    IO_RA3_SetDigitalOutput();
    </code>

*/
#define IO_RA3_SetDigitalOutput() TRISAbits.TRISA3 = 0
/**
  @Summary
    Sets the GPIO pin, RA4, high using LATAbits.LATA4.

  @Description
    Sets the GPIO pin, RA4, high using LATAbits.LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 high (1)
    IO_RA4_SetHigh();
    </code>

*/
#define IO_RA4_SetHigh()          LATAbits.LATA4 = 1
/**
  @Summary
    Sets the GPIO pin, RA4, low using LATAbits.LATA4.

  @Description
    Sets the GPIO pin, RA4, low using LATAbits.LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 low (0)
    IO_RA4_SetLow();
    </code>

*/
#define IO_RA4_SetLow()           LATAbits.LATA4 = 0
/**
  @Summary
    Toggles the GPIO pin, RA4, using LATAbits.LATA4.

  @Description
    Toggles the GPIO pin, RA4, using LATAbits.LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA4
    IO_RA4_Toggle();
    </code>

*/
#define IO_RA4_Toggle()           LATAbits.LATA4 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA4.

  @Description
    Reads the value of the GPIO pin, RA4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA4
    postValue = IO_RA4_GetValue();
    </code>

*/
#define IO_RA4_GetValue()         PORTAbits.RA4
/**
  @Summary
    Configures the GPIO pin, RA4, as an input.

  @Description
    Configures the GPIO pin, RA4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an input
    IO_RA4_SetDigitalInput();
    </code>

*/
#define IO_RA4_SetDigitalInput()  TRISAbits.TRISA4 = 1
/**
  @Summary
    Configures the GPIO pin, RA4, as an output.

  @Description
    Configures the GPIO pin, RA4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an output
    IO_RA4_SetDigitalOutput();
    </code>

*/
#define IO_RA4_SetDigitalOutput() TRISAbits.TRISA4 = 0
/**
  @Summary
    Sets the GPIO pin, RA5, high using LATAbits.LATA5.

  @Description
    Sets the GPIO pin, RA5, high using LATAbits.LATA5.

  @Preconditions
    The RA5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA5 high (1)
    IO_RA5_SetHigh();
    </code>

*/
#define IO_RA5_SetHigh()          LATAbits.LATA5 = 1
/**
  @Summary
    Sets the GPIO pin, RA5, low using LATAbits.LATA5.

  @Description
    Sets the GPIO pin, RA5, low using LATAbits.LATA5.

  @Preconditions
    The RA5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA5 low (0)
    IO_RA5_SetLow();
    </code>

*/
#define IO_RA5_SetLow()           LATAbits.LATA5 = 0
/**
  @Summary
    Toggles the GPIO pin, RA5, using LATAbits.LATA5.

  @Description
    Toggles the GPIO pin, RA5, using LATAbits.LATA5.

  @Preconditions
    The RA5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA5
    IO_RA5_Toggle();
    </code>

*/
#define IO_RA5_Toggle()           LATAbits.LATA5 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA5.

  @Description
    Reads the value of the GPIO pin, RA5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA5
    postValue = IO_RA5_GetValue();
    </code>

*/
#define IO_RA5_GetValue()         PORTAbits.RA5
/**
  @Summary
    Configures the GPIO pin, RA5, as an input.

  @Description
    Configures the GPIO pin, RA5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA5 as an input
    IO_RA5_SetDigitalInput();
    </code>

*/
#define IO_RA5_SetDigitalInput()  TRISAbits.TRISA5 = 1
/**
  @Summary
    Configures the GPIO pin, RA5, as an output.

  @Description
    Configures the GPIO pin, RA5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA5 as an output
    IO_RA5_SetDigitalOutput();
    </code>

*/
#define IO_RA5_SetDigitalOutput() TRISAbits.TRISA5 = 0
/**
  @Summary
    Sets the GPIO pin, RA6, high using LATAbits.LATA6.

  @Description
    Sets the GPIO pin, RA6, high using LATAbits.LATA6.

  @Preconditions
    The RA6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA6 high (1)
    IO_RA6_SetHigh();
    </code>

*/
#define IO_RA6_SetHigh()          LATAbits.LATA6 = 1
/**
  @Summary
    Sets the GPIO pin, RA6, low using LATAbits.LATA6.

  @Description
    Sets the GPIO pin, RA6, low using LATAbits.LATA6.

  @Preconditions
    The RA6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA6 low (0)
    IO_RA6_SetLow();
    </code>

*/
#define IO_RA6_SetLow()           LATAbits.LATA6 = 0
/**
  @Summary
    Toggles the GPIO pin, RA6, using LATAbits.LATA6.

  @Description
    Toggles the GPIO pin, RA6, using LATAbits.LATA6.

  @Preconditions
    The RA6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA6
    IO_RA6_Toggle();
    </code>

*/
#define IO_RA6_Toggle()           LATAbits.LATA6 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA6.

  @Description
    Reads the value of the GPIO pin, RA6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA6
    postValue = IO_RA6_GetValue();
    </code>

*/
#define IO_RA6_GetValue()         PORTAbits.RA6
/**
  @Summary
    Configures the GPIO pin, RA6, as an input.

  @Description
    Configures the GPIO pin, RA6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA6 as an input
    IO_RA6_SetDigitalInput();
    </code>

*/
#define IO_RA6_SetDigitalInput()  TRISAbits.TRISA6 = 1
/**
  @Summary
    Configures the GPIO pin, RA6, as an output.

  @Description
    Configures the GPIO pin, RA6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA6 as an output
    IO_RA6_SetDigitalOutput();
    </code>

*/
#define IO_RA6_SetDigitalOutput() TRISAbits.TRISA6 = 0
/**
  @Summary
    Sets the GPIO pin, RA7, high using LATAbits.LATA7.

  @Description
    Sets the GPIO pin, RA7, high using LATAbits.LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA7 high (1)
    IO_RA7_SetHigh();
    </code>

*/
#define IO_RA7_SetHigh()          LATAbits.LATA7 = 1
/**
  @Summary
    Sets the GPIO pin, RA7, low using LATAbits.LATA7.

  @Description
    Sets the GPIO pin, RA7, low using LATAbits.LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA7 low (0)
    IO_RA7_SetLow();
    </code>

*/
#define IO_RA7_SetLow()           LATAbits.LATA7 = 0
/**
  @Summary
    Toggles the GPIO pin, RA7, using LATAbits.LATA7.

  @Description
    Toggles the GPIO pin, RA7, using LATAbits.LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA7
    IO_RA7_Toggle();
    </code>

*/
#define IO_RA7_Toggle()           LATAbits.LATA7 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA7.

  @Description
    Reads the value of the GPIO pin, RA7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA7
    postValue = IO_RA7_GetValue();
    </code>

*/
#define IO_RA7_GetValue()         PORTAbits.RA7
/**
  @Summary
    Configures the GPIO pin, RA7, as an input.

  @Description
    Configures the GPIO pin, RA7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA7 as an input
    IO_RA7_SetDigitalInput();
    </code>

*/
#define IO_RA7_SetDigitalInput()  TRISAbits.TRISA7 = 1
/**
  @Summary
    Configures the GPIO pin, RA7, as an output.

  @Description
    Configures the GPIO pin, RA7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA7 as an output
    IO_RA7_SetDigitalOutput();
    </code>

*/
#define IO_RA7_SetDigitalOutput() TRISAbits.TRISA7 = 0
/**
  @Summary
    Sets the GPIO pin, RB2, high using LATBbits.LATB2.

  @Description
    Sets the GPIO pin, RB2, high using LATBbits.LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB2 high (1)
    channel_AN2_SetHigh();
    </code>

*/
#define channel_AN2_SetHigh()          LATBbits.LATB2 = 1
/**
  @Summary
    Sets the GPIO pin, RB2, low using LATBbits.LATB2.

  @Description
    Sets the GPIO pin, RB2, low using LATBbits.LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB2 low (0)
    channel_AN2_SetLow();
    </code>

*/
#define channel_AN2_SetLow()           LATBbits.LATB2 = 0
/**
  @Summary
    Toggles the GPIO pin, RB2, using LATBbits.LATB2.

  @Description
    Toggles the GPIO pin, RB2, using LATBbits.LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB2
    channel_AN2_Toggle();
    </code>

*/
#define channel_AN2_Toggle()           LATBbits.LATB2 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB2.

  @Description
    Reads the value of the GPIO pin, RB2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB2
    postValue = channel_AN2_GetValue();
    </code>

*/
#define channel_AN2_GetValue()         PORTBbits.RB2
/**
  @Summary
    Configures the GPIO pin, RB2, as an input.

  @Description
    Configures the GPIO pin, RB2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB2 as an input
    channel_AN2_SetDigitalInput();
    </code>

*/
#define channel_AN2_SetDigitalInput()  TRISBbits.TRISB2 = 1
/**
  @Summary
    Configures the GPIO pin, RB2, as an output.

  @Description
    Configures the GPIO pin, RB2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB2 as an output
    channel_AN2_SetDigitalOutput();
    </code>

*/
#define channel_AN2_SetDigitalOutput() TRISBbits.TRISB2 = 0

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the PIC32MX470F512L
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the MPLAB(c) Code Configurator device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize(void);

#endif
