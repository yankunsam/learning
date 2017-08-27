#!/bin/bash
file $1 | grep 'ELF' > /dev/null
if [ $? -eq 0 ]; then
     evmctl sign --imasig $1 /etc/keys/privkey_evm.pem
else
     evmctl sign --imahash $1 /etc/keys/privkey_evm.pem
fi
