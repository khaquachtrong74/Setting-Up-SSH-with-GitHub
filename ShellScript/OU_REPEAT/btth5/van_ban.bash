#!/bin/bash

read -p "Nhập tên file muốn lưu (khuyên: không dùng dấu)" file_name

if [ -z "$file_name" ]
then
	echo "Empty val"
	exit 1
fi

if [[ -f "$file_name" ]]
then
	touch "$file_name"
fi
while read line
do
	echo "Enter q1 to exit func. "
	if [ "$line" == "q1" ]
	then
		echo "Shutdown program"
		exit 0
	else
		echo "$line" >> "$file_name"
	fi
done

