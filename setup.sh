#!/usr/bin/env bash

mkdir -p target
sudo apt install libkeyutils-dev libnuma-dev lksctp-tools gcc make mingw-w64*

if [ $? -eq 0 ];
then
    make install
fi
