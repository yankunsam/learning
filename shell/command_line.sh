#!/bin/bash
usage()
{
cat <<-EOF >&2
        I will add its implement
EOF
    #exit 0
}
die()
{
    echo "ERROR -$@"
    #exit 1
}
while getopts a:b::h arg
do
    case $arg in
        a) TEST_ARGS_ARRAY+=( "$OPTARG" );;
        h) usage;;
        b) die "b";;
       \?) die "Invalid Option";;
        :) die "$0:must supply  an argument to -$OPTARG";;
   esac
done
for args in ${TEST_ARGS_ARRAY[@]}
do
    case $args in
        -s)
            STDIN=1
            if [ $STDIN -eq 1 ]; then
                echo "yes"
            fi
            ;;
    esac
done
