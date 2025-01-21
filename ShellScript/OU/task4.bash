#!/bin/bash

check(){
	isSo=$1;
	if [[ $isSo =~ ^[0-9]+$ ]];
	then
		echo "true"
	#elif [[ $isSo =~ ^[a-zA-Z]+$ ]]
	#then
	#	echo "false"
	else
		echo "false"
	fi
}
sum(){
	so1=$1;so2=$2
	so3=$3
	#if [[ $(check "$so1") == "true" && $(check "$so2") == "true" && $(check "$so3") == "true" ]]
	#then
	#	sum=$((so1 + so2 + so3))
#		echo "$sum"
#	else
#		echo "none"
#	fi
	if [ $(check "$so1") == "true" ] && [ $(check "$so2") == "true" ] && [ $(check "$so3") == "true" ]

	then
			
		sum=$((so1 + so2 + so3))
		echo "$sum"
		
	fi
}
read -p "NHap so 1" so
read -p "nHap so 2" soo
read -p "nhaP sO 3" sooo
sum "$so" "$soo" "$sooo"

