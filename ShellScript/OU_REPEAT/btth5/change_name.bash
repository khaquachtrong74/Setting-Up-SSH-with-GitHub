#!/bin/bash
echo "Xin chào $USER"
echo "Bạn đang sử dung máy tính $HOSTNAME"

#update change name which is input by user

read -p "Nhập tên máy tính mà bạn muốn đổi thành : " hostName
read -p "Bạn có chắc chắn muốn đổi hay không (Y/n) " choice

if [ -z "$choice" ]
then
	echo "Empty choice, pls try again! "
	exit 1
fi
if [[ "$choice" =~ ^[Yy]$ ]]
then
	sudo hostnamectl set-hostname "$hostName"
	read -p "Bạn nên khởi động máy tính để đổi tên có hiệu lực " c2
	#if [ "$c2" == "Y" ] || [ "$c2" == "y" ]
	if [[ "$c2" =~ ^[Yy]$ ]]
	then
		reboot
	else
		echo "Tên máy tính hiện tại là $HOSTNAME "
	fi
else
	echo "Tên máy tính hiện tại là $HOSTNAME"
fi

