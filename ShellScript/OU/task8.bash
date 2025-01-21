#!/bin/bash
check(){
	so=$1
	if [ $((so%2)) -eq 1 ]
	then
		echo "true"
	else
		echo "false"

	fi
}

read n
if [[ "$n" =~ ^[0-9]+$ ]]
then
	sum=0
	for i in $(seq 1 $n)
	do
		if [ $(check "$i") == "true" ]
		then
			sum=$((sum + i))
		fi
	done
	echo "$sum"
else
	echo "None"
fi
