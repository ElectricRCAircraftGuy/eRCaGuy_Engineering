/*
By Gabriel Staples, 2024

Code snippets of exception handlers
*/


// Local includes
// NA

// 3rd-party includes
// - Located/installed at, for example: "/opt/microchip/xc32/v4.35/pic32mx/include/xc.h". 
// - The `_CP0_GET_CAUSE()` macro is then defined inside
//   "/opt/microchip/xc32/v4.35/pic32mx/include/pic32m-libs/cp0defs.h", for example, and included
//   in `xc.h` via `#include <cp0defs.h>` near the bottom of the `xc.h` file.
#include <xc.h>  // for `_CP0_GET_CAUSE()`, `_CP0_GET_EPC()`

// C includes
#include <stdbool.h>  // for `bool`, `true`


// Note numbers are in parenthesis below. 
// - Ex: `MOD(1)` means Note 1 below applies to `MOD`. `DSPDis(3)` means Note 3 below applies to
//   `DSPDis`, etc.
// 
// > Notes 
// > 1: This feature is only available on PIC32 devices with the MPU core. Refer to the
// >    “CPU” chapter in the specific device data sheet for availability.
// > 2: This feature is only available on PIC32 devices with the M-Class core. Refer to the
// >    “FPU” chapter in the specific device data sheet to determine availability.
// > 3: DSP ASE is not available on all devices. Please consult the “CPU” chapter of the
// >    specific device data sheet to determine availability

static const char * general_exception_cause_long[32] = 
{
    // See:
    // 1. Reference Manual Section 50: CPU: p69 of 
    //    "PIC32M_Family_Reference_Manual/Section 50. CPU for Devices with MIPS32® microAptiv™ and M-Class Cores-60001192B (qpdf --decrypt)_GS_edit.pdf"
    //    - Online: https://ww1.microchip.com/downloads/en/DeviceDoc/60001192B.pdf
    // 2. Datasheet: p128-129 Table 7-1 of
    //    "PIC32MZ2048EFM144/PIC32MZ-Embedded-Connectivity-with-Floating-Point-Unit-Family-Data-Sheet-DS60001320H_GS_edit (qpdf --decrypt).pdf"
    //    - Online: https://ww1.microchip.com/downloads/aemDocuments/documents/MCU32/ProductDocuments/DataSheets/PIC32MZ-Embedded-Connectivity-with-Floating-Point-Unit-Family-Data-Sheet-DS60001320H.pdf
                                                                    // Index
                                                                    // -----
    "Int: Interrupt",                                               // 0
    "MOD(1): TLB modified exception",                               // 1
    "TLBL(1): TLB exception (load or instruction fetch)",           // 2
    "TLBLS(1): TLB exception (store)",                              // 3
    "AdEL: Address error exception (load or instruction fetch)",    // 4
    "AdES: Address error exception (store)",                        // 5
    "IBE: Bus error exception (instruction fetch)",                 // 6
    "DBE: Bus error exception (data reference: load or store)",     // 7
    "Sys: Syscall exception",                                       // 8
    "Bp: Breakpoint exception",                                     // 9
    "RI: Reserved instruction exception",                           // 10
    "CPU: Coprocessor Unusable exception",                          // 11
    "Ov: Arithmetic Overflow exception",                            // 12
    "Tr: Trap exception",                                           // 13
    "-: Reserved",                                                  // 14
    "FPE(2): Floating Point exception",                             // 15
    "-: Reserved",                                                  // 16
    "-: Reserved",                                                  // 17
    "-: Reserved",                                                  // 18
    "TLBRI(1): TLB read-inhibit",                                   // 19
    "TLBEI(1): TLB execute-inhibit",                                // 20
    "-: Reserved",                                                  // 21
    "-: Reserved",                                                  // 22
    "WATCH(1): Reference to WatchHi/WatchLo address",               // 23
    "MCheck(1): Machine check",                                     // 24
    "-: Reserved",                                                  // 25
    "DSPDis(3): DSP ASE state disabled exception",                  // 26
    "-: Reserved",                                                  // 27
    "-: Reserved",                                                  // 28
    "-: Reserved",                                                  // 29
    "-: Reserved",                                                  // 30
    "-: Reserved",                                                  // 31
};

static const char * general_exception_cause_short[32] = 
{
    // See:
    // 1. Reference Manual Section 50: CPU: p69 of 
    //    "PIC32M_Family_Reference_Manual/Section 50. CPU for Devices with MIPS32® microAptiv™ and M-Class Cores-60001192B (qpdf --decrypt)_GS_edit.pdf"
    //    - Online: https://ww1.microchip.com/downloads/en/DeviceDoc/60001192B.pdf
    // 2. Datasheet: p128-129 Table 7-1 of
    //    "PIC32MZ2048EFM144/PIC32MZ-Embedded-Connectivity-with-Floating-Point-Unit-Family-Data-Sheet-DS60001320H_GS_edit (qpdf --decrypt).pdf"
    //    - Online: https://ww1.microchip.com/downloads/aemDocuments/documents/MCU32/ProductDocuments/DataSheets/PIC32MZ-Embedded-Connectivity-with-Floating-Point-Unit-Family-Data-Sheet-DS60001320H.pdf
                    // Index
                    // -----                          
    "Int",          // 0
    "MOD(1)",       // 1
    "TLBL(1)",      // 2
    "TLBLS(1)",     // 3
    "AdEL",         // 4
    "AdES",         // 5
    "IBE",          // 6
    "DBE",          // 7
    "Sys",          // 8
    "Bp",           // 9
    "RI",           // 10
    "CPU",          // 11
    "Ov",           // 12
    "Tr",           // 13
    "-",            // 14
    "FPE(2)",       // 15
    "-",            // 16
    "-",            // 17
    "-",            // 18
    "TLBRI(1)",     // 19
    "TLBEI(1)",     // 20
    "-",            // 21
    "-",            // 22
    "WATCH(1)",     // 23
    "MCheck(1)",    // 24
    "-",            // 25
    "DSPDis(3)",    // 26
    "-",            // 27
    "-",            // 28
    "-",            // 29
    "-",            // 30
    "-",            // 31
};

// Originally copied from:
//  "eRCaGuy_Engineering/Datasheets/Microchip/XC32_Compiler/XC32_UG_EE_Examples/Example5.X/mcc_generated_files/mcc.c", 
// and then modified by me for the PIC32MZ2048EFM144 mcu, by looking at p69 here: 
// "PIC32M_Family_Reference_Manual/Section 50. CPU for Devices with MIPS32® microAptiv™ and M-Class Cores-60001192B (qpdf --decrypt)_GS_edit.pdf"
//
// See also: 
// 1. "eRCaGuy_Engineering/Datasheets/Microchip/README_exceptions_and_handlers.md"
//
// NB: You **must** use the `nomips16` attribute as well! See here: 
// 1. *****Here where they say it's required:
//    https://developerhelp.microchip.com/xwiki/bin/view/products/mcu-mpu/32bit-mcu/PIC32/mx-arch-cpu-overview/exception-mechanism/usage/:
//    > The handler must be attributed with the "nomips16" attribute [e.g., _attribute_((nomips16))]
//    > since the start-up code jumps to this function.
// 2. Here where they recommend it: 
//    https://forum.microchip.com/s/topic/a5C3l000000MDm0EAG/t283004?comment=P-2237738
// void _general_exception_handler()
void __attribute__((nomips16)) _general_exception_handler()
{
    /* Mask off the ExcCode Field from the Cause Register
    Refer to the MIPs Software User's manual */
    uint8_t _excep_code;
    uint8_t _excep_addr;
    const char * _cause_str_short;
    const char * _cause_str_long;
    // If desired while debugging, you may manually change this variable to `true` to exit the
    // exception handler and return to the main program where the exception occurred.
    volatile bool exit_exception_handler = false;

    _excep_code = (_CP0_GET_CAUSE() & 0x0000007C) >> 2;  // Note that 0x7C = 0b01111100
    _excep_addr = _CP0_GET_EPC();
    _cause_str_short  = general_exception_cause_short[_excep_code];
    _cause_str_long  = general_exception_cause_long[_excep_code];

    // Disable interrupts. See the compiler user manual Section 18.8: "Enabling/Disabling
    // Interrupts": 
    // "XC32_Compiler/MPLAB-XC32-Compiler-UG-PIC32M-DS-50002799 [XC32 Compiler User's
    // Guide for PIC32M]_GS_edit.pdf"
    __builtin_disable_interrupts();
    // NB: an alternative way to disable interrupts is shown below, but the compiler built-in 
    // used just above is probably better/clearer. 

    // Now let the watchdog timer reset the PIC32 because it's no longer getting serviced (reset) 
    // by the FreeRTOS idle task hook (`void vApplicationIdleHook( void );`--see: 
    // https://www.freertos.org/a00016.html) which one should add to service it. 
    // - Note: disabling interrupts above is what stops the FreeRTOS scheduler from running. 
    while (exit_exception_handler == false)
    {
        _nop();
    }
}


// EXTRA learning:

// Alternative ways to enable/disable interrupts:
//
// See:
// 1. The IE bit in 
//    "PIC32M_Family_Reference_Manual/Section 50. CPU for Devices with MIPS32® microAptiv™ and M-Class Cores-60001192B (qpdf --decrypt)_GS_edit.pdf"
//    p61, in the "Status Register (CP0 Register 12, Select 0)". 
// 2. "/opt/microchip/xc32/v4.35/pic32mx/include/xc.h". 
// 3. The `_CP0_GET_CAUSE()` macro that is then defined inside
//   "/opt/microchip/xc32/v4.35/pic32mx/include/pic32m-libs/cp0defs.h", for example, and included
//   in `xc.h` via `#include <cp0defs.h>` near the bottom of the `xc.h` file.

void disableInterrupts() 
{
    // NB: CHOOSE 1 OF THESE APPROACHES

    // GS: not tested, but should be correct. 
    // See 60001192B p61: "This bit may be modified separately via the `DI` and `EI` instructions"
    asm volatile("di");  // disable interrupts

    // OR 
    // See DS50002799C compiler user's guide p195: "Enabling/Disabling Interrupts"
    __builtin_disable_interrupts();

    // OR
    // **Clear** just the least-significant (`IE`: interrupt enable) bit. 
    // See 60001192B p59-61: the `IE` bit is bit 0 of the "Status Register 
    // (CP0 Register 12, Select 0)"
    _CP0_SET_STATUS(_CP0_GET_STATUS() & ~(1 << 0));
}

void enableInterrupts() 
{
    // NB: CHOOSE 1 OF THESE APPROACHES

    // GS: not tested, but should be correct. 
    // See 60001192B p61: "This bit may be modified separately via the `DI` and `EI` instructions"
    asm volatile("ei");  // disable interrupts

    // OR 
    // See DS50002799C compiler user's guide p195: "Enabling/Disabling Interrupts"
    __builtin_enable_interrupts();

    // OR
    // **Set** just the least-significant (`IE`: interrupt enable) bit. 
    // See 60001192B p59-61: the `IE` bit is bit 0 of the "Status Register 
    // (CP0 Register 12, Select 0)"
    _CP0_SET_STATUS(_CP0_GET_STATUS() | (1 << 0));
}
