#!/bin/bash
ima_id=`keyctl newring _ima @u`
evmctl import --rsa /etc/keys/pubkey_ima.pem $ima_id
evm_id=`keyctl newring _evm @u`
evmctl import --rsa /etc/keys/pubkey_evm.pem $evm_id

