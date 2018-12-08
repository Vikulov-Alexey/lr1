ifneq ($(KERNELRELEASE),)
	obj-m := hello.o
else
	KDIR := /lib/modules/4.13.0-43-generic/build/

all:
	$(MAKE) -C $(KDIR) M=$$PWD
endif
