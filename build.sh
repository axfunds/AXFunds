#! /bin/bash
# Ubuntu 16.04
cd src/
apt install -y   build-essential  libssl-dev libdb++-dev libboost-all-dev libqrencode-dev  libqt4-dev libminiupnpc-dev
make -f makefile.unix -j8
strip axfd
mv axfd ../
cd ..
