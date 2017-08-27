#!/bin/bash
if [ $1 -eq 1 ]; then
    find / \( -fstype rootfs -o -fstype ext4 \) -type f -exec head -n 1 {} >/dev/null \;
else
  find / \( -fstype rootfs -o -fstype ext4 \) -type f -exec $1 {} >/dev/null \; 
fi
