#!/bin/bash

read -p "Nhập tên file vào đây " file_name
read -p "Nhập định dạng file vào đây " etx
read -p "Nhap số lượng file vào " soluong
if [ ! -e "$file_name" ]
then
	for ((i=0; i < soluong; i++))
	do
		touch "$file_name$i.$etx"
	done
fi
