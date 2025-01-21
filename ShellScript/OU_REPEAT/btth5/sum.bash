#!/bin/bash

read -p "Nhập số 1 " numb1
read -p "Nhập số 2 " numb2
read -p "Nhập số 3 " numb3

check(){
	numb=$1
	if [ -z "$numb" ]
	then
		echo "false"
		exit 1
	fi
	if [[ ! $numb =~ ^[0-9]+$ ]]
	then
		echo "false"
		exit 1
	fi
	if [ $numb -lt 10 ] || [ $numb -gt 99 ]
	then
		echo "false"
	else
		echo "true"
	fi
}
echo "$(check $numb1)"

if [ $(check "$numb1") == "false" ]
then
	echo "Invalid val"
	exit 0
fi
if [ $(check "$numb2") == "false" ]
then
	echo "Invalid val"
	exit 0
fi
if [ $(check "$numb3") == "false" ]
then
	echo "Invalid val"
	exit 0
fi
sum=$(($numb1 + numb2 + numb3))
echo "Sum 3 numb is := $sum"
