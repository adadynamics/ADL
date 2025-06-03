#!/usr/bin/env bash


sudo apt install libkeyutils-dev libnuma-dev lksctp-tools gcc make

if [ $? -eq 0 ];
then
    make install
fi
