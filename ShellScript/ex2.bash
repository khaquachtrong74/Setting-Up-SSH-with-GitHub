#!/bin/bash
#check is number is odd or even
echo -n "Enter your numbers: "
read numb
if [ $((numb % 2)) -eq 0 ];then
	echo "$numb is even"
else
	echo "$numb is odd"
fi
