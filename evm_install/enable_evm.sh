#!/bin/bash
echo "you should run the script in the current directory to have a good feeling"
echo ""

if [ $(whoami) != "root" ]; then
    echo "you should run this script as root!!!"
    exit 1
fi
echo "Are you run with kernle command line parameter "ima_tcb ima_appraise_tcb ima_appraise=fix evm=fix "? if not you should add them  to the kernel command line,like "/etc/default/grub on Ubuntu*" and reboot and run this script again"
if [ ! -e "/etc/keys" ]; then
    mkdir -p /etc/keys
fi
echo "generate the evm_key"
su -c 'modprobe trusted encrypted'
su -c 'keyctl add user kmk-user "`dd if=/dev/urandom bs=1 count=32 2>/dev/null`" @u'
su -c 'keyctl pipe `keyctl search @u user kmk-user` > /etc/keys/kmk-user.blob'
su -c 'keyctl add user evm-key "new user:kmk-user 32" @u'
su -c 'keyctl pipe `keyctl search @u encrypted evm-key` >/etc/keys/evm-user.blob'

openssl genrsa -out /etc/keys/privkey_evm.pem 1024
openssl rsa -pubout -in /etc/keys/privkey_evm.pem -out /etc/keys/pubkey_evm.pem
openssl genrsa -out /etc/keys/privkey_ima.pem 1024
openssl rsa -pubout -in /etc/keys/privkey_ima.pem -out /etc/keys/pubkey_ima.pem
if [ $? -ne 0 ];then
    echo "generate a key failed"
    exit 1
else 
    echo "Congratualtions! You generate the key successfully!"
fi

mkdir -p /etc/sysconfig/
cp ./masterkey /etc/sysconfig/
cp ./evm  /etc/sysconfig/

cp ./ima.sh /etc/initramfs-tools/hooks/
chmod +x /etc/initramfs-tools/hooks/ima.sh
chmod +x ./ima.sh
update-initramfs -k $(uname -r) -u
echo "Now,you have updated the current initramfs in "/boot/initrd.img-$(uname -r)""
echo "It will label the entire file system,so you can have a tea :)"
if [ $? -ne 0 ]; then
    echo "some errors occured when labeling the entire file system,it maybe not reboot successfully in the next time"
else
echo "you can reboot only with "ima_tcb ima_appraise_tcb" and enjoy the fun which IMA/EVM brings,yea,maybe bad dreams "
