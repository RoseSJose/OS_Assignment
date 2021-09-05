# OS_Assignment1
## Linux Dualboot

Commands used for the dual booting of lastest stable Linux kernal with the current Linux version.

`uname -r` \
`mkdir OS_Assg` \
`cd OS_Assg` \
`wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.14.1.tar.xz` \
`tar -xf linux-5.14.1.tar.xz` \
`cd linux-5.14.1` \
`cp /boot/config-5.8.0-55-generic .config` \
`sudo apt install build-essential libncurses-dev flex bison libssl-dev libelf-dev` \
`make menuconfig` \
`make -j4` \
`sudo make modules_install` \
`sudo make install` \
`sudo reboot` \
`uname -a`
