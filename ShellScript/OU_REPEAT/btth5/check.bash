#!/bin/bash
# Kiểm tra đối số truyền vào có phải số hay không
numb=$1
if [ -z "$numb" ]
then
	echo "false"
	exit 1
elif [[ ! "$numb" =~ ^[0-9]+$ ]]
then
	echo "false"
	exit 1
else
	echo "true"
	exit 0
fi
