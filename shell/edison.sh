#!/data/ltp/bash
str=1
printinfo()
{
    echo "printinfo"
    return 1
}
if [ -z "" ]; then
    echo yes
fi

echo "yes_1" || echo yes_2
