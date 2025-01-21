#!/bin/bash

path="$HOME/src02.cpp"
dsk="$HOME/dsk.cpp"
# Khong kha thi vi for chi dong duoc tung chu
flag="false"
cat "$path" | while IFS= read -r line
do
	if [ "$line" == "int main(){" ]
	then
		flag="true"
		echo "$line" >> "$dsk";
		echo "const auto start{std::chrono::steady_clock::now()};" >> "$dsk"
		continue
	fi
	if [ "$flag" == "true" ]
	then
		
		echo "$line" >> "$dsk"
	fi
	if [ "$line" == "//" ]
	then
		echo "const auto end{std::chrono::steady_clock::now()};" >> "$dsk"
		echo "const std::chrono::duration<double>elapsed_seconds{end-start};" >> "$dsk"
		echo 'cout<<"TIME EXCUTE"<<elapsed_seconds.count()<<endl' >> "$dsk"
	fi
	#echo "$line"
done
cpp "$dsk"
rm "$dsk"
