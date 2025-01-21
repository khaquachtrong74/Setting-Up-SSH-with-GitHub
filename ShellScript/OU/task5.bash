#!/bin/bash
sumAll=0
check(){
	so=$1
	if [[ "$so" =~ ^[0-9]+$ ]]
	then
		echo "true"
	else
		echo "false"
	fi
}

sum(){
	so=$1
	if [ $(check "$so") == "true" ]
	then
		sumAll=$((sumAll + so))
	fi
}
sum "$1"
sum "$2"
sum "$3"
echo "$sumAll"
