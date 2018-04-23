#!/bin/bash
configfile="/root/data/config.ini"
genesisfile="/root/data/genesis.json"
datadir="/opt/data/*"
rm -rf $datadir
command=$(cleos create key)
privatekey=$(echo $command | awk '{print $3}')
echo "privatekey:" $privatekey
publickkey=$(echo $command | awk '{print $6}')
echo "publickkey:" $publickkey
if [ $(hostname) == "eosio"  ]; then
  sed -i 's/\"initial_key\"\:.*/"initial_key": "'$publickkey'",/g' $genesisfile
fi
sed  -i 's/private-key.*/private-key=["'$publickkey'","'$privatekey'"]/g' $configfile
sed -i 's/.*producer-name.*/producer-name = '$(hostname)'/g' /root/data/config.ini

kill $(ps -aux | grep nodeos | grep -v "grep" | awk '{print $2}')
nodeos --data-dir /opt/data --config-dir /root/data/ > /opt/data/stdout.txt 2> /opt/data/stderr.txt & echo $! > /opt/data/eosd.pid
#nodeos --data-dir /opt/data --config-dir /root/data/
sleep 3
cleos wallet create > /root/data/wallet.password
cleos wallet import $privatekey
