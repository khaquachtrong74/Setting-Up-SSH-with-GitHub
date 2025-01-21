#!/bin/bash

read -p "Nhap path " path
read -p "Nhap dinh dang " etx

# path:= $HOME/SHELL/OU_REPEAT/btth5/te
if [ -d "$path" ]
then
	if [ -n "$etx" ]
	then
		rm "$path"/*."$etx"
	fi
else
	echo "Thu muc khong ton tai"
fi
