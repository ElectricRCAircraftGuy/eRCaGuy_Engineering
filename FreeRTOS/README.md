

# See also

1. https://github.com/ElectricRCAircraftGuy/eRCaGuy_hello_world/tree/master/FreeRTOS


# Main links

1. FreeRTOS Kernel Developer Docs: https://www.freertos.org/features.html
1. API Reference: https://www.freertos.org/a00106.html
1. Official FreeRTOS source code: https://github.com/FreeRTOS
    1. Official FreeRTOS kernel source code: https://github.com/FreeRTOS/FreeRTOS-Kernel
        1. Example `FreeRTOSConfig.h` file: https://github.com/FreeRTOS/FreeRTOS-Kernel/blob/main/examples/template_configuration/FreeRTOSConfig.h
        1. My modifications to the above file: [`eRCaGuy_hello_world/FreeRTOS/FreeRTOSConfig_GS_customizations.h`](https://github.com/ElectricRCAircraftGuy/eRCaGuy_hello_world/blob/master/FreeRTOS/FreeRTOSConfig_GS_customizations.h)
        1. Compare to see my modifications:
            ```bash
            meld FreeRTOSConfig.h FreeRTOSConfig_GS_customizations.h
            ```
1. Official FreeRTOS Kernel Book: 
    1. Main link: https://freertos.org/Documentation/02-Kernel/07-Books-and-manual/01-RTOS_book
    1. Mastering the FreeRTOS Real Time Kernel - A Hands On Tutorial Guide
        1. Main link: https://freertos.org/Documentation/02-Kernel/07-Books-and-manual/01-RTOS_book
        1. On GitHub: 
            1. https://github.com/FreeRTOS/FreeRTOS-Kernel-Book
            1. Table of Contents: https://github.com/FreeRTOS/FreeRTOS-Kernel-Book/blob/main/toc.md
        1. Downloadable PDF: https://github.com/FreeRTOS/FreeRTOS-Kernel-Book/releases/download/V1.1.0/Mastering-the-FreeRTOS-Real-Time-Kernel.v1.1.0.pdf
            1. Companion Example Source Code: https://freertos.org/media/2024/source-code-for-book-examples.20240207.zip
    1. The FreeRTOS Reference Manual: https://freertos.org/media/2018/FreeRTOS_Reference_Manual_V10.0.0.pdf
