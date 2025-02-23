
_These notes are a scratch work / work in progress._


# QEMU (Quick Emulator)

Notes and info. 

1. https://www.qemu.org/
    1. Official documentation: https://www.qemu.org/docs/master/

1. https://en.wikipedia.org/wiki/QEMU

# Build

Download and build: https://www.qemu.org/download/#source:

```bash
# Install dependencies
sudo apt update
sudo apt install libglib2.0-dev

wget https://download.qemu.org/qemu-9.2.0.tar.xz
tar xvJf qemu-9.2.0.tar.xz
cd qemu-9.2.0
time ./configure
time make -j "$(nproc)"  
# this worked thus far

# sudo make install # ??????????
```

1. https://github.com/sergev/qemu/wiki

    serge.vakulenko@gmail.com
    https://www.linkedin.com/in/sergevakulenko/
    http://sima.ai/
    *****https://vak.dreamwidth.org/ - https://vak.dreamwidth.org/1339994.html



# Modern instructions to build and run QEMU for PIC32

Added here: https://github.com/sergev/qemu/issues/17

_Tested and works on Ubuntu 22.04_

Reference: https://github.com/sergev/qemu/wiki#how-to-build-qemu-for-mips

```bash
# clone the main project repo
git clone https://github.com/sergev/qemu.git
# clone the wiki repo
git clone https://github.com/sergev/qemu.wiki.git

cd qemu

sudo apt update
sudo apt install plocate
sudo apt install python2
sudo apt install libpixman-1-dev
sudo apt install libfdt-dev
sudo apt install zlib1g-dev
sudo apt install libglib2.0-dev
sudo apt install libsdl1.2-dev
sudo apt install uml-utilities  # for `tunctl`

time ./configure --prefix=/usr/local/qemu-mips --target-list=mipsel-softmmu --python="$(which python2)"

gcc --version  # I have 'gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0'

time make CFLAGS="-Wno-error -isystem/usr/include/glib-2.0 -isystem/usr/lib/$(uname -m)-linux-gnu/glib-2.0/include" -j "$(nproc)"
```

The executable is now located at: 
```bash
./mipsel-softmmu/qemu-system-mipsel
```

Install it!: 
```bash
ln -si "$(pwd)/mipsel-softmmu/qemu-system-mipsel" ~/bin/qemu-pic32
```


Get the binaries from: https://github.com/sergev/qemu/wiki#run-pic32-simulation

```bash
mkdir -p ../../boards/binaries
curl -L https://raw.githubusercontent.com/wiki/sergev/qemu/binaries/boot-wifire.hex > ../../boards/binaries/boot-wifire.hex
curl -L https://raw.githubusercontent.com/wiki/sergev/qemu/binaries/vmunix.hex > ../../boards/binaries/vmunix.hex
curl -L https://raw.githubusercontent.com/wiki/sergev/qemu/binaries/litebsd.zip > ../../boards/binaries/litebsd.zip

# extract binaries/litebsd.zip into binaries/litebsd.img
unzip ../../boards/binaries/litebsd.zip -d ../../boards/binaries

# get the rest
curl -L https://raw.githubusercontent.com/wiki/sergev/qemu/binaries/boot-max32.hex > ../../boards/binaries/boot-max32.hex
curl -L https://raw.githubusercontent.com/wiki/sergev/qemu/binaries/hello-max32.hex > ../../boards/binaries/hello-max32.hex
curl -L https://raw.githubusercontent.com/wiki/sergev/qemu/binaries/unix.hex > ../../boards/binaries/unix.hex
curl -L https://raw.githubusercontent.com/wiki/sergev/qemu/binaries/retrobsd.zip > ../../boards/binaries/retrobsd.zip
unzip ../../boards/binaries/retrobsd.zip -d ../../boards/binaries
```

# Run on emulated PIC32MZ

```bash
./mipsel-softmmu/qemu-system-mipsel -machine pic32mz-wifire \
    -nographic \
    -monitor none \
    -serial vc \
    -serial vc \
    -serial vc \
    -serial stdio \
    -bios "../../boards/binaries/boot-wifire.hex" \
    -kernel "../../boards/binaries/vmunix.hex" \
    -sd "../../boards/binaries/litebsd.img"
```

Login with username `root`; no password. 

Exit with `halt -q`. 

See here: https://github.com/sergev/qemu/wiki/LiteBSD-Example

Trying a couple more: 
```bash
# Works!
./mipsel-softmmu/qemu-system-mipsel -machine pic32mx7-max32 \
    -nographic \
    -monitor none \
    -serial stdio \
    -bios ../../boards/binaries/boot-max32.hex \
    -kernel ../../boards/binaries/hello-max32.hex

# Works!
wget https://raw.githubusercontent.com/chipKIT32/chipKIT-digiboot/refs/heads/master/BootloadersCurrent-hex/chipKIT-Max32.hex
mv chipKIT-Max32.hex ../../boards/binaries/
./mipsel-softmmu/qemu-system-mipsel -machine pic32mx7-max32 \
    -nographic \
    -monitor none \
    -serial stdio \
    -bios ../../boards/binaries/chipKIT-Max32.hex \
    -kernel ../../boards/binaries/hello-max32.hex

# Fails to boot
./mipsel-softmmu/qemu-system-mipsel -machine pic32mx7-max32 \
    -nographic \
    -monitor none \
    -serial stdio \
    -bios ../../boards/binaries/boot-max32.hex \
    -kernel ../../boards/binaries/unix.hex \
    -sd ../../boards/binaries/retrobsd.img

# mix the two: run the hex file while passing in the sd card image
# Result: yeah; runs just fine; plugging in an SD card to a dev board doesn't block hello world
# from printing over serial :)
./mipsel-softmmu/qemu-system-mipsel -machine pic32mx7-max32 \
    -nographic \
    -monitor none \
    -serial stdio \
    -bios ../../boards/binaries/boot-max32.hex \
    -kernel ../../boards/binaries/hello-max32.hex \
    -sd ../../boards/binaries/retrobsd.img

```



## References

1. My answer: [`fatal error: glib.h: No such file or directory` when compiling with gcc: How to install `locate` and `glib`, and then tell `gcc` where to find `glib.h` and `glibconfig.h`](https://stackoverflow.com/a/79403528/4561887)


# Notes to self

https://www.qemu.org/contribute/ - `git clone https://gitlab.com/qemu-project/qemu.git`

These are the only commits on the `sergev/qemu` repo that are NOT on the main qemu repo: 
```bash
QEMU/ercaguy/qemu$ git lg ^qemu/master HEAD
*   a2e0277dfe - (HEAD -> master, upstream/master, origin/master, origin/HEAD) Merge pull request #8 from cratuki/20200309_cturner_fix_compile_issues (4 years, 11 months ago) <Serge Vakulenko>
|\  
| * bc15faea59 - Addresses compile issues. (4 years, 11 months ago) <Craig Turner>
|/  
* 28a4189a91 - Pic32 ethernet: remove nic_can_receive() function as deprecated. (9 years ago) <vak>
* bee000e212 - Pic32 ethernet: support a chain of descriptors on transmit. (9 years ago) <vak>
* 9ba80495fd - Pic32 SD card: allow read past the end of image file. (9 years ago) <Serge Vakulenko>
* 76b0e43e0c - Pic32mz: implement read access to port H, J and K registers. (9 years ago) <Serge Vakulenko>
* 5ec6c068c3 - Pic32 ethernet driver: make MII ADVRT register writable. (9 years ago) <Serge Vakulenko>
* 368ee05e9c - Get rid of "WARNING: Image format was not specified" message for -sd option. (10 years ago) <Serge Vakulenko>
* 83b474ace3 - Two new machine platforms: pic32mz7 and pic32mz. (10 years ago) <Serge Vakulenko>
* 90468c4854 - Two new processor variants: M4K and microAptivP. (10 years ago) <Serge Vakulenko>
* 9054304ab0 - Added support for external interrupt controller (EIC) mode. (10 years ago) <Serge Vakulenko>
* bae17a1d8c - Fixed random index generation for TLBWR instruction. It was not quite random and did not skip Wired entries. (10 years ago) <Serge Vakulenko>
* 1789b08679 - Stop simulation when processor is suspended forever by WAIT instruction with interrupts disabled. (10 years ago) <Serge Vakulenko>
* 70b2274eeb - Speed of MIPS CPU timer made configurable per platform. (10 years ago) <Serge Vakulenko>
```


PIC32MZ Boards: 

1. pic32mz-explorer16	PIC32MZ on Microchip Explorer-16 board
    https://www.microchip.com/en-us/development-tool/dm240001
    - Ethernet? 
1. pic32mz-meb2	        PIC32MZ on Microchip MEB-II board
    https://www.microchip.com/en-us/development-tool/dm320005-2
    - Goes along with this board I think: https://www.microchip.com/en-us/development-tool/dm320007
        - Uses PIC32MZ2048EFH144 or PIC32MZ2048EFM144 [same as our board!]
    - Ethernet
1. pic32mz-wifire	    PIC32MZ on chipKIT WiFire board
    https://www.microchip.com/en-us/development-tool/tdgl021-2


Works:
```bash
./mipsel-softmmu/qemu-system-mipsel -machine pic32mz-wifire \
    -nographic \
    -monitor none \
    -serial vc \
    -serial vc \
    -serial vc \
    -serial stdio \
    -bios "../../boards/binaries/boot-wifire.hex" \
    -kernel "../../boards/binaries/vmunix.hex" \
    -sd "../../boards/binaries/litebsd.img"
```

Works now!: 
```bash
sudo tunctl -t tap0 -u $USER
sudo ifconfig tap0 20.2.2.2
./mipsel-softmmu/qemu-system-mipsel -machine pic32mz-meb2 \
    -nographic \
    -monitor none \
    -serial stdio \
    -net nic \
    -net tap,ifname=tap0,script=no,downscript=no \
    -kernel ../../boards/binaries/vmunix-meb2.hex \
    -sd ../../boards/binaries/litebsd.img
```

Trying this (`-d` adds qemu debug info): 
```bash
sudo ip link set tap0 up
sudo ip addr add 192.168.0.1/24 dev tap0
./mipsel-softmmu/qemu-system-mipsel -machine pic32mz-meb2 \
    -nographic \
    -monitor none \
    -serial stdio \
    -net nic \
    -net tap,ifname=tap0,script=no,downscript=no \
    -kernel ../../boards/binaries/vmunix.hex \
    -sd ../../boards/binaries/litebsd.img \
    -d int,cpu_reset,guest_errors

# no Ethernet TAP device: 
./mipsel-softmmu/qemu-system-mipsel -machine pic32mz-meb2 \
    -nographic \
    -monitor none \
    -serial stdio \
    -kernel ../../boards/binaries/vmunix.hex \
    -sd ../../boards/binaries/litebsd.img
```


```bash
sudo apt-get update
sudo apt-get install uml-utilities bridge-utils

sudo tunctl -t tap0 -u $USER
sudo ip link set tap0 up
sudo ip addr del 192.168.0.1/24 dev tap0
sudo ip addr add 192.168.0.1/24 dev tap0

./mipsel-softmmu/qemu-system-mipsel -machine pic32mz-meb2 \
    -nographic \
    -monitor none \
    -serial stdio \
    -net nic \
    -net tap,ifname=tap0,script=no,downscript=no \
    -kernel ../../boards/binaries/vmunix.hex \
    -sd ../../boards/binaries/litebsd.img \
    -d int,cpu_reset

# Bring down the TAP device and remove it
sudo ip link set tap0 down
sudo tunctl -d tap0
```


Study: 
1. https://www.google.com/search?q=pic32+qemu&oq=pic32+qemu+&gs_lcrp=EgZjaHJvbWUqBggAEEUYOzIGCAAQRRg7MgYIARBFGDsyBggCEEUYOzIGCAMQRRg8MgYIBBBFGDwyBggFEEUYQdIBCDMzMDVqMGo0qAIAsAIB&sourceid=chrome&ie=UTF-8
1. [looks very useful] https://blog.gistre.epita.fr/posts/besma.talbi-2024-10-10-navigating_the_complexity_of_emulating_diverse_microcontroller_architectures-pre-emulation/

