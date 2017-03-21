#!/bin/bash

su -c 'mkdir -p /etc/keys'
su -c 'modprobe trusted encrypted'
su -c 'keyctl add user kmk-user "`dd if=/dev/urandom bs=1 count=32 2>/dev/null`" @u'
su -c 'keyctl pipe `keyctl search @u user kmk-user` > /etc/keys/kmk-user.blob'
su -c 'keyctl add user evm-key "new user:kmk-user 32" @u'
#su -c 'keyctl pipe `keyctl search @u encrypted evm-key` >/etc/keys/evm-user.blob'
su -c 'keyctl pipe `keyctl search @u user evm-key` >/etc/keys/evm-user.blob'
openssl genrsa -out /etc/keys/privkey_evm.pem 1024
openssl rsa -pubout -in /etc/keys/privkey_evm.pem -out /etc/keys/pubkey_evm.pem
openssl genrsa -out /etc/keys/privkey_ima.pem 1024
openssl rsa -pubout -in /etc/keys/privkey_ima.pem -out /etc/keys/pubkey_ima.pem


