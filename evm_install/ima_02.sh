#!/bin/sh -e

PREREQ=""

# Output pre-requisites
prereqs()
{
        echo "$PREREQ"
}

case "$1" in
    prereqs)
        prereqs
        exit 0
        ;;
esac

grep -q "ima=off" /proc/cmdline && exit 1

mount -n -t securityfs securityfs /sys/kernel/security

IMA_POLICY=/sys/kernel/security/ima/policy
LSM_POLICY=/etc/ima_policy

#grep -v "^#" $LSM_POLICY >$IMA_POLICY

# import EVM HMAC key
keyctl show |grep -q kmk || keyctl add user kmk "testing123" @u
#keyctl add encrypted evm-key "load `cat /etc/keys/evm-key`" @u
keyctl add encrypted evm-key "new user:kmk-user 32" @u
#keyctl revoke kmk

# import Module public key
mod_id=`keyctl newring _module @u`
evmctl import --rsa /etc/keys/pubkey_evm.pem $mod_id

# import IMA public key
ima_id=`keyctl newring _ima @u`
evmctl import --rsa /etc/keys/pubkey_evm.pem $ima_id

# import EVM public key
evm_id=`keyctl newring _evm @u`
evmctl import --rsa /etc/keys/pubkey_evm.pem $evm_id

# enable EVM
echo "1" > /sys/kernel/security/evm

# enable module checking
#echo "1" > /sys/kernel/security/module_check
