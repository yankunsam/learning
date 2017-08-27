#!/bin/bash
cat  <<-EOF >&1
hello
hello
sam
sam
EOF

LOG_FILE=`mktemp`
echo $LOG_FILE
