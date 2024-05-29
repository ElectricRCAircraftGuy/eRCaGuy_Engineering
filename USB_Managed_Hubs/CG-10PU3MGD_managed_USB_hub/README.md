
# CG-10PU3MGD 10 Port Managed USB 3.2 Gen 1 Hub w/ 15KV ESD Surge Protection Per Port ($175 + $28 power supply)

1. Order page: 
    1. Hub ($175): https://www.usbgear.com/cg-10pu3mgd.html
    1. Power supply ($28): https://www.usbgear.com/cg-10pu3mgd.html - an external power supply is required to power this hub.
1. Manufacturer's page [software download here]: https://www.coolgear.com/product/10-port-managed-usb-3-hub-w-15kv-esd-surge-protection-on-off-per-port-control-software
    1. User manual: https://www.coolgear.com/wp-content/uploads/2020/12/CG-10Pu3MGD-Installation-Guide.pdf
    1. Software: (link above) --> Drivers & Software --> choose the correct one for your OS (Windows, Mac, or Linux)

        Note: on Linux there is only the CLI interface tool. On Windows, there is a GUI interface *and* the CLI tool.


## Notes and limitations

1. From Note 1 on p2 in the manual: [CG-10PU3MGD_Manual_GS_edit.pdf](CG-10PU3MGD_Manual_GS_edit.pdf):

    > Note 1: The last USB port (Port 10) of this hub does NOT support USB2.0/1.1 devices because it is used to communicate with the managing utilities. However, it still supports USB3.2 Gen 1 devices.

    So, don't try to use USB 1.1 or 2.0 devices on port 10.

1. An external power supply is required to power this hub. See the recommended one above for $28.
1. Turning off a USB port does *not* disconnect the USB _data pins_ to that device. It only disconnects the _power_ to the device. 

    So, if the USB device is powered externally, meaning _separately from_ the main USB plug going into the USB port, then turning off that port will NOT disconnect this USB device. This can happen, for instance, when a PIC32 [PICKit 5](https://www.microchip.com/en-us/development-tool/pg164150) microcontroller debugger is plugged into a target board via an ICSP cable, and the target device provides power to the power pin on the ICSP cable, thereby _powering the debugger from the target_. In such a case, if you'd like to remotely power cycle the debugger, you must disconnect the power cable from the ICSP cable going to the debugger, _or_ turn off that USB port on the hub _and_ power cycle the target. 


## CLI interface

- On Linux, it is called [`cusbi`](Managed-USB-Hub-Software-Linux-x86-64-coolgear.com_/cusbi) and you have to manually extract it.  
- On Windows, it is called `cusbc` and it gets automatically installed at `C:\Program Files (x86)\Centos\USB Hub Administrator\CUSBC.exe` and added to your Windows PATH when you install the GUI **"USB Hub Administrator"** tool. 

Running `which cusbc` in Git Bash on Windows shows that this executable is located at `/c/Program Files (x86)/Centos/USB Hub Administrator/cusbc`. 

#### Usage style: 

_Tested on Linux Ubuntu 22.04 and in Windows 10._ 

Notice that in Git Bash on Windows you must use `//` instead of `/` for the command line options.

```bash
# Linux terminal
# Help menu
./cusbi /h
./cusbi /?  # (same as above)
# Query all USB hubs connected
./cusbi /Q

# Windows Command Prompt
# Help menu
cusbc /h
cusbc /?  # (same as above)
# Query all USB hubs connected
cusbc /Q

# Windows Git Bash terminal
cusbc //h
cusbc //?  # (same as above)
# Query all USB hubs connected
cusbc //Q
```

Full run and output of help menu in the Windows Git Bash terminal:
```bash
$ cusbc //h
CUSBC v1.03
Usage: CUSBC command [password] [argument]
command:
   /Q       query (no password is required)
   Usage:   CUSBC /Q [option]
            CUSBC /Q:COMn [option]
   /Q:      query all Managed USB Hubs
   /Q:COMn  query the Managed USB Hub on COMn (n = 1 to 255)
   option   -F    output in formatted string

   /S       set port states (password is required)
   Usage:   CUSBC /S:COMn [pass] [states]
   COMn     control port number of the Managed USB Hub (n = 1 to 255)
   pass     password, default is used if this argument is not specified
   states   port states to be set on, off, toggle or given binary/hex states
            1:3,4    port 3 and 4 on
            0:3      port 3 off
            T:1,2    toggle port 1 and 2 states
            0:ALL    all ports off
            B:0101   binary, port 1 and 3 on, port 2, 4 off
            H:A601   byte hex (little-endian A6 01 ...):
                     port 2, 3, 6, 8, 9 on, the others off

   /F       set port states and save to flash as the initial states
   Usage:   similar to set port states (/S)

   /P       change password (8 characters maximum)
   Usage:   CUSBC /P:COMn [old_password] new_password
   COMn     control port number of the Managed USB Hub (n = 1 to 255)
   old_password   old password, default assumed if omitted
   new_password   new password

   /G       get current port states (no password is required)
   Usage:   CUSBC /G:COMn [option]
   /G:COMn  control port number of the Managed USB Hub (n = 1 to 255)
   option   -B    output in formatted binary string
            -H    output in formatted little-endian hex string

   /W       save states to flash as the initial states (password is required)
   Usage:   CUSBC /W:COMn [pass]

   /D       restore to factory default settings (password is required)
   Usage:   CUSBC /D:COMn [pass]

   /R       reset the entire Managed USB Hub (password is required)
   Usage:   CUSBC /R:COMn [pass]

Example: To control port 3 of the hub, follow the steps below:
CUSBC /Q  (auto serach all the hubs connected)
CUSBC /S:COM3 0:3  (turn OFF port 3, assumed COM3 is found by the /Q command)
CUSBC /S:COM3 1:3  (turn ON port 3)
```

More example commands in Git Bash on Windows:

Assume that `cusbc //Q` shows:
```none
1 USB Managed Hub(s) Found.
COM7, 10 ports, On=1,2,3,4,5,6,7,8,9,10, Off=None, FW=v02
```

Here are some commands:
```bash
# Query this hub for its full status
# Example output:
#       COM7, 10 ports, On=1,5,6,7,8,9,10, Off=2,3,4, FW=v02
cusbc //Q:COM7

# Query this hub for only its port ON/OFF status
# Example output:
#       On=1,5,6,7,8,9,10 Off=2,3,4
cusbc //G:COM7


# Turn various ports on and off on this hub

cusbc //S:COM7 0:1       # Turn OFF port 1
cusbc //S:COM7 1:1       # Turn ON port 1

cusbc //S:COM7 0:2,3,4   # Turn OFF ports 2, 3, and 4
cusbc //S:COM7 1:2,3,4   # Turn ON ports 2, 3, and 4

cusbc //S:COM7 T:1,2     # Toggle ports 1 and 2

cusbc //S:COM7 0:ALL     # Turn OFF all ports
cusbc //S:COM7 1:ALL     # Turn ON all ports
cusbc //S:COM7 T:ALL     # Toggle all ports

cusbc //F:COM7 0:1,2     # Turn OFF port 1 and 2 and save these states to flash as the initial states
```

Note that if also running the GUI application on Windows, you must click the "Auto Search" button, as shown below, to refresh the GUI with the latest status of the hub (as shown in the right panel in the GUI) if you have changed its state using the CLI tool. Clicking that button makes it update the GUI status:

<p align="left" width="100%">
    <a href="https://github.com/ElectricRCAircraftGuy/eRCaGuy_Engineering/assets/6842199/11887400-51e3-4d1c-9862-7ab60d804df1">
        <img width="100%" src="https://github.com/ElectricRCAircraftGuy/eRCaGuy_Engineering/assets/6842199/11887400-51e3-4d1c-9862-7ab60d804df1"> 
    </a>
</p>

[BEST] To easily query the hub's state after each command, simply append `&& cusbc //G:COM7` to each command, like this:
```bash
cusbc //S:COM7 0:1 && cusbc //G:COM7  # Turn OFF port 1, then query the hub's state
cusbc //S:COM7 1:1 && cusbc //G:COM7  # Turn ON port 1, then query the hub's state
```
