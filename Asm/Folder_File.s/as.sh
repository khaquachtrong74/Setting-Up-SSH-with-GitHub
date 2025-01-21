#!/bin/bash

# Kiểm tra xem có đủ tham số không
if [ $# -eq 0 ]; then
    echo "Sử dụng: $0 <tên file .s>"
    exit 1
fi

# Tên file .s được truyền vào
input_file="$1"

# Kiểm tra xem file có tồn tại không
if [ ! -f "$input_file" ]; then
    echo "File $input_file không tồn tại"
    exit 1
fi

# Kiểm tra xem file có phải là file .s không
if [[ "$input_file" != *.s ]]; then
    echo "File $input_file không phải là file .s"
    exit 1
fi

# Tạo thư mục excuteFile nếu chưa tồn tại
mkdir -p excuteFile

# Chạy file .s
as "$input_file" -o "${input_file%.s}.o"
if [ $? -ne 0 ]; then
    echo "Lỗi khi biên dịch file $input_file"
    exit 1
fi
ld "${input_file%.s}.o" -o "${input_file%.s}"
if [ $? -ne 0 ]; then
        echo "Linking failed"
        return 1
    fi
    "./${basename}"
# Di chuyển tất cả các file không phải .s vào thư mục excuteFile
for file in *; do
    if [[ "$file" != *.s ]] && [ "$file" != "excuteFile" ] && [ "$file" != "$(basename "$0")" ]; then
        mv "$file" excuteFile/
    fi
done