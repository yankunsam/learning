FROM ubuntu:16.04
RUN apt-get update
RUN apt-get install -y libssl1.0.0 libssl-dev vim
RUN mkdir -p /opt/data
COPY nodeos /usr/local/bin/nodeos
COPY cleos /usr/local/bin/cleos
COPY keosd /usr/local/bin/keosd
#COPY scholar-server-config /root/config
COPY contracts /root/contracts
COPY data /root/data
COPY biosrun.sh /root/data/biosrun.sh
EXPOSE 8888
EXPOSE 8889
