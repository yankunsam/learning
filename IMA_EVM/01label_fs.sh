#!/bin/bash
find / \( -fstype rootfs -o -fstype ext4 \) -type f -exec head -n 1 {} >/dev/null \;
