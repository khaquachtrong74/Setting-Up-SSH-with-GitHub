// go mod là một công cụ quản lý module trong Go
// Quản lý các dependencies và phiên bản của các thư viện
// Theo dõi các thư viện sử dụng trong dự án
// Tự động tải và cài đặt các package cần 
// Quản lý phiên bản chính xác của từng package

module student-manager

go 1.18 //phiên bản hiện tại

// tạo module với lệnh : go mod init <tên-module>
// Cập nhập: go mod tidy
// tải về các dependencies: go mod download
// sao chép dependencies vào thư mục vendor: go mod vendor
// Liệt kê tất cả dependencies: go list -m all
