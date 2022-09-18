obj-m += misc_char_device_driver.o
KDIR := /lib/modules/$(shell uname -r)/build
CFLAGS += -msoft-float -msse -msse2

all: clean build install

build:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	


clean: uninstall
	$(MAKE) -C $(KDIR) M=$(PWD) clean


install:
	- sudo insmod misc_char_device_driver.ko
	sudo lsmod | grep misc_char_device_driver
	- sudo chmod a+rwx /dev/eudyptula

uninstall:
	- sudo rmmod misc_char_device_driver


test:
	- cat /dev/eudyptula
	@ echo 
	- echo "ayedaemon" > /dev/eudyptula
	@ echo 
	- echo "something" > /dev/eudyptula