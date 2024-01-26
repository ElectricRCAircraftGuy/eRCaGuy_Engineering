
# XC32 Compiler User's Guides, documentation, release notes, and code examples


# References

1. [MAIN PG WHICH LINKS TO EVERYTHING ELSE] MPLAB® XC32 Compiler - https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers/xc32 - see "MPLAB XC32 Compiler Documentation" section at the bottom!
1. [NO PDF--JUST THIS WEBPAGE!] Release Notes for the MPLAB® XC32 C/C++ Compiler for SAM and PIC32 MCUs - https://ww1.microchip.com/downloads/aemDocuments/documents/DEV/ProductDocuments/ReleaseNotes/README.html
1. 


# Notes


## Critical sections and interrupt guards in PIC32 microcontrollers

Interrupt guards for critical sections in PIC32 microcontrollers can be done like this:

```c
// Disable interrupts
__builtin_disable_interrupts();

// Critical section code here

// Enable interrupts
__builtin_enable_interrupts();
```

But, that's not ISR-safe. You don't want to enable nested interrupts inside an ISR if they were previously disabled. So, do this instead:

```c
// back up the interrupt state
// - Note: the `__builtin_*` functions are part of the XC32 compiler, and 
//   are documented in DS50002799C (MPLAB® XC32 C/C++ Compiler User's Guide
//   for PIC32M MCUs; XC32 Compiler for PIC32M) p195, p265 (the assembly 
//   code output for the functions is around here), etc.
unsigned int isr_state = __builtin_get_isr_state();
__builtin_disable_interrupts();

// Critical section code here

// restore the interrupt state
__builtin_set_isr_state(isr_state);
```

