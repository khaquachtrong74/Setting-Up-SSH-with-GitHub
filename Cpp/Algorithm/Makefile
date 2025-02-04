# Tên file thực thi
TARGET = main

# Trình biên dịch và cờ biên dịch

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

# Các file nguồn và file object
SRC = main.cpp array.cpp
OBJ = $(SRC:.cpp=.o)

# Luật mặc định khi gõ 'make'
all: $(TARGET) rm -f main.o array.o

# Luật để liên kết các file object thành file thực thi
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@rm -f $(OBJ)
	
# Luật biên dịch từng file .cpp thành .o
%.o: %.cpp array.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Lệnh dọn dẹp file biên dịch tạm thời
.PHONY: clean 
clean:
	rm -f $(OBJ) $(TARGET)

# Lệnh để build lại từ đầu
rebuild: clean all

