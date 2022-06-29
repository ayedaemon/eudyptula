CFLAGS_helloworld.o = -DDEBUG

obj-m += HelloWorld.o

KDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean: uninstall
	$(MAKE) -C $(KDIR) M=$(PWD) clean

install: default
	sudo insmod HelloWorld.ko
	lsmod | grep HelloWorld

uninstall:
	- lsmod | grep HelloWorld
	- sudo rmmod HelloWorld.ko

reload: uninstall clean default install
	@echo -e "\nDONE"