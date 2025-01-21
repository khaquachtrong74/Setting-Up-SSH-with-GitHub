#!/bin/bash
echo -n "Xin chào : "; read name
echo -n "Hãy nhập số tuổi vào đây : "; read age

chao() {
	yourName=$1
	yourAge=$2
	echo "Xin chào: $yourName"
	echo "Năm nay bạn $yourAge tuổi"
}
chao $name $age

