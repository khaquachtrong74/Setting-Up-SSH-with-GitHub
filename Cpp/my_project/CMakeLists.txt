#Xác định phiên bản CMake tối thiểu
# Cải thiện tính tương thích khi
# những người khác làm việc trên này
cmake_minimum_required(VERSION 3.10)

# Đặt tên cho dự án
project(RunesL)

#Chuẩn ngôn ngữ trong dự án
set(CMAKE_CXX_STANDARD 11)

# Biên dịch tệp tại src/main.cpp
# Tạo tệp thực thi mới là MP
# add_executable(MP src/main.cpp)

add_subdirectory(as)
