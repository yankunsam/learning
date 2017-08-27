#!/data/ltp/bash
export PATH=/data/ltp/bin:$PATH
ls  &
sleep 3
#ps -o pid | grep -q $!
ps  | grep  $!
if [ $? -eq 0 ]; then
	echo "success"
else
	echo "failed"
fi
