#!/bin/bash

read -p "Nhập tên: " name
read -p "Nhập tuổi: " age
read -p "Nhập giới tính: " gender
if [ -z "$name" ] || [ -z "$age" ] || [ -z "$gender" ]
then
	echo "None"
	exit 0
else
	if [ $age -lt 20 ]
	then

		echo "Xin chào bạn $name"
		echo "Năm nay bạn $age tuổi"
	elif [ $age -ge 20 ] && [ $age -lt 45 ]
	then
		if [ "$gender" == "nam" ]
		then
			echo "Xin chào anh $name"
			echo "Năm nay anh $age tuổi"
		elif [ "$gender" == "nu" ]
		then

			echo "Xin chào chị $name"
			echo "Năm nay chị $age tuổi"
		else
			echo "NONE"
			exit 1
		fi
	elif [ $age -ge 45 ]
	then
		echo "$gender"
		if [ "$gender" == "nam" ]
		then
			echo "Xin chào chú $name"
			echo "Năm nay chú $age tuổi"
		elif [ "$gender" == "nu" ]
		then

			echo "Xin chào cô $name"
			echo "Năm nay cô $age tuổi"
		else
			echo "NONE"
			exit 1
		fi
	else
		echo "NONE"
		exit 1
	fi	
fi

