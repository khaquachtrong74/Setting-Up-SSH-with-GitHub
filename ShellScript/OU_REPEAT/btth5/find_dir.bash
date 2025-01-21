#!/bin/bash

read -p "Nhập tên folder vào : " folder_name

if [ -f "$folder_name" ]
then
	find / -type f -name "$folder_name" 2>/dev/null
	echo "Đã tìm thấy!"
else
	echo "Không tìm thấy!"
fi
