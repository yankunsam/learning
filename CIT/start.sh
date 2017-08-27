#!/bin/bash
if [ "$(whoami) != "root"" ]; then
    echo "you should run this as root"
fi
mkdir /tmp/vtpm$1
chown -R tss:root  /tmp/vtpm$1
swtpm_setup --tpm-state /tmp/vtpm$1  --createek
export TPM_PATH=/tmp/vtpm$1
swtpm_cuse -n vtpm$1
swtpm_ioctl -i /dev/vtpm0
	
if [ "$#" -ne 2 ]; then
    echo "you should specific the image file to start"
    exit 1
fi
#
#if [ "$1" -ne "1" && "$1" -ne "0" ]; then
#    echo "you should input 1|0 image_file "
#    exit 1
#fi

if [ "$2" == "ubuntu_agent.img" ]; then
    /usr/local/bin/qemu-system-x86_64  -display sdl -enable-kvm -tpmdev cuse-tpm,id=tpm0,path=/dev/vtpm$1 -device tpm-tis,tpmdev=tpm0 -net tap,ifname=tap0,script=no,downscript=no  -net nic,macaddr=52:54:00:12:01:0$1 -m 1024 -boot c -bios $SEABIOS/bios.bin -boot menu=on $2 
fi
if [ "$2" == "ubuntu_server.img" ]; then
    /usr/local/bin/qemu-system-x86_64  -display sdl -enable-kvm -tpmdev cuse-tpm,id=tpm0,path=/dev/vtpm$1 -device tpm-tis,tpmdev=tpm0 -net tap,ifname=tap0,script=no,downscript=no  -net nic,macaddr=52:54:00:12:01:0$1 -m 1024 -boot c -bios $SEABIOS/bios.bin -boot menu=on $2 
fi
if [ "$2" == "ubuntu_server_v2.1.img" ]; then
    /usr/local/bin/qemu-system-x86_64  -display sdl -enable-kvm -tpmdev cuse-tpm,id=tpm0,path=/dev/vtpm$1 -device tpm-tis,tpmdev=tpm0 -net tap,ifname=tap0,script=no,downscript=no  -net nic,macaddr=52:54:00:12:01:0$1 -m 1024 -boot c -bios $SEABIOS/bios.bin -boot menu=on $2 
fi
if [ "$2" == "ubuntu_100G.img" ]; then
    /usr/local/bin/qemu-system-x86_64  -display sdl -enable-kvm -tpmdev cuse-tpm,id=tpm0,path=/dev/vtpm$1 -device tpm-tis,tpmdev=tpm0 -net tap,ifname=tap0,script=no,downscript=no  -net nic,macaddr=52:54:00:12:01:0$1 -m 1024 -boot c -bios $SEABIOS/bios.bin -boot menu=on $2 
fi
if [ X"$2" != X"" ]; then
    /usr/local/bin/qemu-system-x86_64  -display sdl -enable-kvm -tpmdev cuse-tpm,id=tpm0,path=/dev/vtpm$1 -device tpm-tis,tpmdev=tpm0 -net tap,ifname=tap0,script=no,downscript=no  -net nic,macaddr=52:54:00:12:01:0$1 -m 1024 -boot c -bios $SEABIOS/bios.bin -boot menu=on $2 
fi
