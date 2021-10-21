Save the Makefile
Run the following commands:

make
sudo insmod driver.ko
sudo mknod /dev/mydevice c 240 1
sudo chmod a+r+w /dev/mydevice
gcc run_driver.c
./a.out

This report has been submitted by:
Ganesh Gopan B190466CS
Pavithra Rajan B190632CS
Rose S Jose B190839CS
Shada Faisal B190180CS
Vishnu C B190402CS

