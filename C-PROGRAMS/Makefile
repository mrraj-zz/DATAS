# set to your kernel tree
KERNEL  = /usr/src/linux-2.4.0
#KERNEL  = /usr/src/linux-2.2.18

# get the Linux architecture. Needed to find proper include file for CFLAGS
ARCH=$(shell uname -m | sed -e s/i.86/i386/ -e s/sun4u/sparc64/ -e s/arm.*/arm/ -e s/sa110/arm/)
# set default flags to compile module
CFLAGS = -D__KERNEL__ -DMODULE -I$(KERNEL)/include
CFLAGS+= -Wall -Wstrict-prototypes -O2 -fomit-frame-pointer -fno-strict-aliasing

all:	mmap_mod.o mmap

# get configuration of kernel
include $(KERNEL)/.config
# modify CFLAGS with architecture specific flags
include $(KERNEL)/arch/${ARCH}/Makefile

# enable the module versions, if configured in kernel source tree
ifdef CONFIG_MODVERSIONS
CFLAGS+= -DMODVERSIONS -include $(KERNEL)/include/linux/modversions.h
endif
# enable SMP, if configured in kernel source tree
ifdef CONFIG_SMP
CFLAGS+= -D__SMP__
endif

# note: we are compiling the driver object file and then linking
# we link it into the module. With just one object file as in
# this example this is not needed. We can just load the object
# file produced by gcc 

# link the mmap driver module
mmap_mod.o:	mmap_drv.o
	ld -r -o mmap_mod.o mmap_drv.o

# compile the mmap driver
mmap_drv.o:	mmap_drv.c
	gcc $(CFLAGS) -c mmap_drv.c
# compile and link the test program
mmap:	mmap.c
	gcc -o mmap mmap.c

clean:
	rm -f *.o mmap
