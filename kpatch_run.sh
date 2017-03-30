#!/bin/bash
#echo "[the modified  file] [ the original file] [ patch file]"
diff -u $1 $2  > $3
#kpatch-build -s .  -v ./vmlinux  -t vmlinux --skip-gcc-check mem.patch
kpatch-build -s .  -v ./vmlinux  -t vmlinux --skip-gcc-check $3
