#!/bin/bash
if [ ! -e "/home/sam/qemu_image/$1" ]; then
    qemu-img create -f qcow2 $1 100G
fi
/usr/local/bin/qemu-system-x86_64 -display sdl -enable-kvm -cdrom $2  -m 1024 -boot d -bios $SEABIOS/bios.bin -boot menu=on -tpmdev\
 cuse-tpm,id=tpm0,path=/dev/vtpm0 \
-device tpm-tis,tpmdev=tpm0 $1

