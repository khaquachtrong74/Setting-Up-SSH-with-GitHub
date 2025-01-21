#!/bin/bash
check(){
	so=$1
	if [[ "$so" =~ ^[0-9]+$ ]]
	then
		echo "true"
	else
		echo "false"
	fi
}
realNumber=0
read -p "Nhập một số bất kì : " realNumber
sumAll=0
if [ $(check "$realNumber") == "false" ]
then
	echo "0"
	exit 0
else
	for i in $(seq 1 $realNumber)
	do
		sumAll=$((sumAll + i))
	done
	echo "Tong la $sumAll"
fi
