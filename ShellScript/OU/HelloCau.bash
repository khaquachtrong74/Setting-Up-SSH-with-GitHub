#!/bin/bash

chao(){
	xungHo=$1
	tuoi=$2
	echo "Xin chào $xungHo "
	echo "Năm nay $xungHo đã $tuoi tuổi rồi!"
}


echo -n "Hãy nhập tên : ";read name
echo -n "Hãy nhập năm sinh: ";read year
echo -n "Hãy nhập giới tính: ";read gender


currentYear=$(date +%Y)
currentOld=$((currentYear - year))
if [ $currentOld -lt 20 ];
then
	if [[ "$gender" == "nam" || "$gender" == "Nam" || "$gender" == "NAM" ]]
	then
		chao "Bạn" "$currentOld"
	else
		chao "Em" "$currentOld"
	fi
elif [ $currentOld -gt 20 -a $currentOld -lt 45 ];then
	if [[ "$gender" == "nam" || "$gender" == "Nam" || "$gender" == "NAM" ]]
	then
		chao "Anh" "$currentOld"
	else
		chao "Chị" "$currentOld"
	fi
else
	if [[ "$gender" == "nam" || "$gender" == "Nam" || "$gender" == "NAM" ]]
	then
		chao "Chú" "$currentOld"
	else
		chao "Cô" "$currentOld"
	fi
fi
