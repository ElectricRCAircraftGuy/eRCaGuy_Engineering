
1. Application Notes (ANs)
    1. \*\*\*\*\*AN1388 - PIC32 Bootloader - https://www.microchip.com/en-us/application-notes/an1388
        1. https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ApplicationNotes/ApplicationNotes/01388B.pdf
        1. \*\*\*\*\*[same document, but shorter link, it seems]: https://ww1.microchip.com/downloads/en/AppNotes/01388B.pdf
        1. \*\*\*\*\*AN1388 Source Code: https://ww1.microchip.com/downloads/en/AppNotes/AN1388%20Source%20Code%202014_02_14.zip - the bootloader application source code

            Contains `AN1388 Source Code 2014_02_14.zip`, which contains `AN1388 Source Code 2014_02_14.exe`.

            If you run the .exe file on a Windows 11 or similar computer, it will go through a "Setup - AN1388 Source Code" Setup Wizard and copy all source code into a `AN1388_Source_Code_2014_02_14` folder. 

    1. **Windows PC Bootloader `.exe` application** source code: [also see above]: go here: https://www.microchip.com/en-us/application-notes/an1388 --> look under the "Files" section --> find "AN1388 Source Code" --> click the "Download" link to the right of it (direct link: [`AN1388 Source Code 2014_02_14.zip`](https://ww1.microchip.com/downloads/en/AppNotes/AN1388%20Source%20Code%202014_02_14.zip)). Extract the zip file and run the [`AN1388 Source Code 2014_02_14.exe`](<./AN1388 Source Code 2014_02_14.exe>) installer. It will copy all source code into an [`AN1388_Source_Code_2014_02_14`](./AN1388_Source_Code_2014_02_14) folder. 
    
        The Windows bootloader application which connects to the mcu's bootloader over Ethernet and then allows you to flash the main application's `.hex` file image is then located here: [`AN1388_Source_Code_2014_02_14/PIC32_Bootloaders/PC Application/PIC32UBL.exe`](<./AN1388_Source_Code_2014_02_14/PIC32_Bootloaders/PC Application/PIC32UBL.exe>). 

        The source code for that Windows application is in this directory here: [`AN1388_Source_Code_2014_02_14/PIC32_Bootloaders/PC Application/PIC32UBL/`](<./AN1388_Source_Code_2014_02_14/PIC32_Bootloaders/PC Application/PIC32UBL>).

        Windows build instructions for `PIC32UBL.exe` are here: [`AN1388_Source_Code_2014_02_14/PIC32_Bootloaders/PC Application/Readme.txt`](<./AN1388_Source_Code_2014_02_14/PIC32_Bootloaders/PC Application/Readme.txt>).

        _Licenses:_

        The software and PC application are subject to Microchip's licenses as shown in:
        1. Appendix A of the [AN1388 PDF](<./AN1388-PIC32 Bootloader-01388B [qpdf --decrypt]_GS_edit.pdf>).
        1. The license agreement that comes up when you run the source code .exe installer above. 



