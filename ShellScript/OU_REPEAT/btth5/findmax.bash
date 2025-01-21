#!/bin/bash

read -p "Nhập số 1 : " numb1
read -p "Nhập số 2 : " numb2
read -p "Nhập số 3 : " numb3

echo $(./check.bash "$numb1")
if [ $(./check.bash "$numb1") == "false" ]
then
	echo "Invalid val"
	exit 1
fi
if [ $(./check.bash "$numb3") == "false" ]
then
	echo "Invalid val"
	exit 1
fi
if [ $(./check.bash "$numb3") == "false" ]
then
	echo "Invalid val"
	exit 1
fi

if [ $numb1 -gt $numb2 ]
then
	
	if [ $numb1 -lt $numb3 ]
	then
		echo "Số lớn nhất là số 3 ($numb3)"
	else
		echo "Số lớn nhất là số 1 ($numb1)"
	fi
else
	if [ $numb2 -lt $numb3 ]
	then
		echo "Số lớn nhất là số 3 ($numb3)"
	else
		echo "Số lớn nhất là số 2 ($numb2)"
	fi
fi
