#!/bin/bash
mkdir /tmp/vtpm0

chown -R tss:root  /tmp/vtpm0
swtpm_setup --tpm-state /tmp/vtpm0  --createek
export TPM_PATH=/tmp/vtpm0
swtpm_cuse -n vtpm0
