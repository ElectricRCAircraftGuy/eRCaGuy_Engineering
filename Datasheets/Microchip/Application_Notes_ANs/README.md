
1. Application Notes (ANs)
    1. \*\*\*\*\*AN1388 - PIC32 Bootloader - https://www.microchip.com/en-us/application-notes/an1388
        1. https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ApplicationNotes/ApplicationNotes/01388B.pdf
        1. \*\*\*\*\*[same document, but shorter link, it seems]: https://ww1.microchip.com/downloads/en/AppNotes/01388B.pdf
        1. \*\*\*\*\*AN1388 Source Code: https://ww1.microchip.com/downloads/en/AppNotes/AN1388%20Source%20Code%202014_02_14.zip - the bootloader application source code

            Contains `AN1388 Source Code 2014_02_14.zip`, which contains `AN1388 Source Code 2014_02_14.exe`.

            If you run the .exe file on a Windows 11 or similar computer, it will go through a "Setup - AN1388 Source Code" Setup Wizard and copy all source code into a `AN1388_Source_Code_2014_02_14` folder. 

    1. **Windows PC Bootloader `.exe` application**: allows flashing a main application through a PIC32 mcu's bootloader, over Ethernet. 

        Source code: [also see above]: go here: https://www.microchip.com/en-us/application-notes/an1388 --> look under the "Files" section --> find "AN1388 Source Code" --> click the "Download" link to the right of it (direct link: [`AN1388 Source Code 2014_02_14.zip`](https://ww1.microchip.com/downloads/en/AppNotes/AN1388%20Source%20Code%202014_02_14.zip)). Extract the zip file and run the [`AN1388 Source Code 2014_02_14.exe`](<./AN1388 Source Code 2014_02_14.exe>) installer. It will copy all source code into an [`AN1388_Source_Code_2014_02_14`](./AN1388_Source_Code_2014_02_14) folder. 
    
        The Windows bootloader application which connects to the mcu's bootloader over Ethernet and then allows you to flash the main application's `.hex` file image is then located here: [`AN1388_Source_Code_2014_02_14/PIC32_Bootloaders/PC Application/PIC32UBL.exe`](<./AN1388_Source_Code_2014_02_14/PIC32_Bootloaders/PC Application/PIC32UBL.exe>). 

        The source code for that Windows application is in this directory here: [`AN1388_Source_Code_2014_02_14/PIC32_Bootloaders/PC Application/PIC32UBL/`](<./AN1388_Source_Code_2014_02_14/PIC32_Bootloaders/PC Application/PIC32UBL>).

        Windows build instructions for `PIC32UBL.exe` are here: [`AN1388_Source_Code_2014_02_14/PIC32_Bootloaders/PC Application/Readme.txt`](<./AN1388_Source_Code_2014_02_14/PIC32_Bootloaders/PC Application/Readme.txt>).

        _Licenses:_

        The software and PC application are subject to Microchip's licenses as shown in:
        1. Appendix A of the [AN1388 PDF](<./AN1388-PIC32 Bootloader-01388B [qpdf --decrypt]_GS_edit.pdf>).
        1. The license agreement that comes up when you run the source code .exe installer above. 


## PIC32 `#pragma config` Device Configuration Registers

See: 
1. https://developerhelp.microchip.com/xwiki/bin/view/products/mcu-mpu/32bit-mcu/PIC32/configuration-registers/
1. [../XC32_Compiler/MPLAB-XC32-Compiler-UG-PIC32M-DS-50002799 [XC32 Compiler User's Guide for PIC32M]_GS_edit.pdf](<../XC32_Compiler/MPLAB-XC32-Compiler-UG-PIC32M-DS-50002799 [XC32 Compiler User's Guide for PIC32M]_GS_edit.pdf>)
1. \*\*\*\*\*+[`/opt/microchip/xc32/v1.42/docs/config_docs/32mz2048efm144.html`](/opt/microchip/xc32/v1.42/docs/config_docs/32mz2048efm144.html) - this fully describes all `#pragma config` settings for the PIC32MZ2048EFM144 microcontroller, for example, for this XC32 v1.42 compiler version.
    1. See also the descriptions and default values here: [`~/microchip/harmony/v2_01b/utilities/mhc/config/PIC32MZ2048EFM144.hconfig`](<../../../../../../microchip/harmony/v2_01b/utilities/mhc/config/PIC32MZ2048EFM144.hconfig>)
1. Default generic (non-chip-specifici) `.ld` linker script file (ends in `.x` here, but is a _generic, non-chip-specific_ `.ld` linker script nonetheless): [`/opt/microchip/xc32/v1.42/pic32mx/lib/ldscripts/elf32pic32mx.x`](/opt/microchip/xc32/v1.42/pic32mx/lib/ldscripts/elf32pic32mx.x)
    1. From step 3 in Appendix C on p11 of [`AN1388-PIC32 Bootloader-01388B [qpdf --decrypt]_GS_edit.pdf`](<AN1388-PIC32 Bootloader-01388B [qpdf --decrypt]_GS_edit.pdf>).
    1. \*\*\*\*\*Example full linker script for a particular chip: [`/opt/microchip/xc32/v1.42/pic32mx/lib/proc/32MZ2048EFM144/p32MZ2048EFM144.ld`](/opt/microchip/xc32/v1.42/pic32mx/lib/proc/32MZ2048EFM144/p32MZ2048EFM144.ld) - "Default linker script, for normal executables" (see the top of the file, line 38).
    1. [`/opt/microchip/xc32/v1.42/pic32mx/lib/proc/32MZ2048EFM144/p32MZ2048EFM144_pic.ld`](/opt/microchip/xc32/v1.42/pic32mx/lib/proc/32MZ2048EFM144/p32MZ2048EFM144_pic.ld) - "Default linker script, for position independent executables" (see the top of the file, line 38).
        - I don't yet understand the differences.


