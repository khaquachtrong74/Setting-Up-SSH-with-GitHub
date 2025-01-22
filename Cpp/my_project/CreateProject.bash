#!/bin/bash

if [ $# -lt 1 ]; then
	echo "Usage: $0 <project_name>"
	exit 1
fi

if [ -d "$1" ]; then
	echo "Project dir already exists!"
	exit 1
fi
mkdir "$1" && cd "$1" && mkdir src && mkdir build && cd src && touch main.cpp 

# Main.cpp
cat <<EOF >main.cpp
#include <iostream>

int main(){
	std::cout<<"Hello, Destroyer!"<<std::endl;
	return 0;
}
EOF

cd .. && touch Guide.txt

# Guide.txt
echo "File tutorial: ./$1/src/Guid.txt" >> Guide.txt
echo "cd to ${1}/build and use the code " >> Guide.txt
echo "cmake .. && make" >> Guide.txt
echo "Next, you just call ./nameFileExcute to run your code" >> Guide.txt

# CMakeLists.txt set up default
cat <<EOF >CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(Project_$1)
set(CMAKE_CXX_STANDARD 11)
add_executable(Project_${1}_Executable src/main.cpp)
EOF

cat Guide.txt && cd ..
if [ -f CMakeLists.txt ]
then
	if ! grep -q "add_subdirectory($1)" CMakeLists.txt;then
		echo "add_subdirectory($1)" >> CMakeLists.txt
	fi
fi
