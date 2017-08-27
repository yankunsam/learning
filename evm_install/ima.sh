#!/bin/sh

echo "Adding IMA binaries"

. /usr/share/initramfs-tools/hook-functions

copy_exec /etc/keys/evm-key
copy_exec /etc/keys/pubkey_evm.pem
copy_exec /etc/ima_policy
copy_exec /bin/keyctl
copy_exec /usr/bin/evmctl /bin/evmctl
