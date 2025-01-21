#!/bin/bash
so1=0
so2=0
menu(){
	echo "1 Bé làm toán cộng"
	echo "2- Bé làm toán trừ"
	echo "3- Bé làm toán nhân"
	echo "4- Bé làm toán chia"
	echo "0- Thoát chương trình"
}

input(){
	read -p "Nhập số đầu tiên: " soz
	read -p "Nhập số thứ hai: " sox
	so1="$soz"
	so2="$sox"
}
output(){
	echo -n "Phép tính "
	if [ "$1" -eq 1 ]
	then
		sum=$((so1 + so2))
		echo -n "cộng $sum"
	elif [ "$1" -eq 2 ]
	then
		minus=$((so1 - so2))
		echo -n "trừ $minus"
	elif [ "$1" -eq 3 ]
	then
		multi=$((so1 * so2))
		echo -n "nhân $multi"
	elif [ "$1" -eq 4 ]
	then
		if [ "$so2" -eq 0 ]
		then
			echo "invalid value"
			exit 0
		fi
		divide=$((so1 / so2))
		echo -n "chia $divide"
	else
		echo "0"
		exit 0
	fi
}


echo "CHƯƠNG TRÌNH BÉ LÀM TOÁN"
menu
input
while true
do
	read luaChon
	output "$luaChon"
done



