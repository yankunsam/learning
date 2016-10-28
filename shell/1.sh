#!/bin/sh
list=$(ls /sys/bus/pci/devices | tr '\n' '\t' )
list=$(echo "$list" | tr -d '\r')
for file in ${list[$@]}
do
	echo $file
done
