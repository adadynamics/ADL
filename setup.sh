#!/usr/bin/env bash

mkdir -p target

sudo dpkg --add-architecture i386 && apt-get update && apt-get install wine32:i386

if [ $? -ne 0 ]
then
	exit 1
fi


sudo apt install make build-essential git mysql-server libmysqlclient-dev libkeyutils-dev libnuma-dev lksctp-tools gcc make mingw-w64* valgrind wine -y

if [ $? -ne 0 ]
then
	exit 1
fi


sudo apt update && apt upgrade && apt autoremove && apt autopurge && apt autoclean

if [ $? -eq 0 ];
then
    make
    make unix_install
fi
