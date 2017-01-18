#!/bin/bash
str=1
printinfo()
{
    echo "printinfo"
    return 0
}
printinfo &&  echo "yes"
