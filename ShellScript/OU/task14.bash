#!/bin/bash

read -p "Nhap ten thu muc ban muon tao: " nameFile

if [[ -d "$nameFile" ]]
then
	echo "Thư mục đã tồn tại."
else
	# 2>dev/null ẩn các thông báo lỗi (nếu có)
	mkdir "$nameFile" 2>/dev/null
	# dùng $? để ghi nhận mã thoát của mkdir
	if [[ $? -eq 0 ]]
	then
		echo "Da tao file thanh cong"
	else
		echo "Tao file that bai"
	fi
fi

