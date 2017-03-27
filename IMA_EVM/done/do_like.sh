#!/bin/bash
ima_id="`awk '/\.ima/ { printf "%d", "0x"$1; }' /proc/keys`"
evmctl import /home/sam/Downloads/linux-4.8/certs/signing_key.x509  $ima_id
evmctl ima_sign --k /home/sam/Downloads/linux-4.8/certs/signing_key.pem /home/sam/Templates/last -v



