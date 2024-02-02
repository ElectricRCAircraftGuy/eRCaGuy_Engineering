
# [PIC32M Family Reference Manual](https://microchipdeveloper.com/xwiki/bin/view/products/mcu-mpu/32bit-mcu/PIC32/family-reference-pages/manual/)

1. [Section 50. CPU for Devices with MIPS32® microAptiv™ and M-Class Cores](https://ww1.microchip.com/downloads/en/DeviceDoc/60001192B.pdf)

    1. p7. 50.2.2 Core Timer

        > The Count register is incremented every two system clock (SYSCLK) cycles.
    
        GS notes: `SYS_CLK_FREQ` is defined in `system_config.h`, so, we can define `CORE_TIMER_FREQ` as follows, since the core timer runs at half the system clock, per the quote above:

        ```c
        #include "system_config.h"
        #define CORE_TIMER_FREQ_HZ (SYS_CLK_FREQ/2)
        ```
