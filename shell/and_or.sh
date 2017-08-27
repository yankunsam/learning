#!/bin/bash
str=1
printinfo()
{
    echo "printinfo"
    return 1
}
if [ -z "" ]; then
    echo yes
fi

[ -z "" ] || echo yes_2
[ -z "abc" ] && echo n""
