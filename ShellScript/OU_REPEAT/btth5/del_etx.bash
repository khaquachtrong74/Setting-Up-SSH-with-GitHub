#!/bin/bash

read -p "Nhập tên file vào đây " file_name
#read -p "Nhập loại tệp vào đây f || d || e " type
read -p "Nhập định dạng file vào đây " etx
#echo "$file_name*"

rm find -f "$file_name"*
