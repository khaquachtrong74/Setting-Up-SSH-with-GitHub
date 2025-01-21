cmake_minimum_required(VERSION 3.10)

# Tên dự án
project(MyProject)

# C++ tiêu chuẩn
set(CMAKE_CXX_STANDARD 17)

# Thêm đường dẫn tới thư mục `include` của Crow
# Giúp CMake biết nơi để tìm thư viện Crow
# include_directories("${CMAKE_SOURCE_DIR}/Crow/include")
# include_directories("${CMAKE_SOURCE_DIR}/asio/asio/include")
# Thêm executable
add_executable(MyExecutable main.cpp)
