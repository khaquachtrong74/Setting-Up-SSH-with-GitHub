#!/bin/bash

read -p "Nhập số lượng số nguyên mà bạn muốn : " n

total=0
for ((i = 0; i <= n; i++))
do
	total=$((total + i))
done
echo "Tổng là $total"
