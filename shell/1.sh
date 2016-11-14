#!/bin/bash
list=$(ls /sys/bus/pci/devices | tr '\n' '\t' )
list=$(echo "$list" | tr -d '\r')
for file in ${list[$@]}
do
		if [ -n ${!file}];then
			echo ${!file}
		fi
done
