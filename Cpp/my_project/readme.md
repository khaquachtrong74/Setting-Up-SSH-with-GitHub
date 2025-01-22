# Hướng dẫn sử dụng 
1. CMakeLists.txt nằm cùng cấp với CreateProject.bash và DeleteProject.bash sẽ được coi là CMakeLists.txt ROOT, nó sẽ chứa thêm dòng lệnh add_directory(project_name) mỗi khi bạn tạo một project mới ở file của mình.
2. Lệnh trong CreateProject.bash sẽ tạo cho bạn 1 project với dạng cây thư mục như sau.
  1. ![image](https://github.com/user-attachments/assets/4313d45f-e7e3-4434-b093-b99dc20d7619)
  2. CMakeLists.txt là cấu hình của project con này (Cấu hình do mình cài mặc định, bạn có thể tuỳ chỉnh). Và một tệp Guide.txt cùng cấp (có thể bỏ qua nếu bạn đã biết làm) và 2 thư mục build và src
     1. src sẽ là nơi thư mục bạn viết code
     2. build là nơi bạn sẽ thực thi dòng lệnh theo tệp Guide.txt để biên dịch và thực thi chương trình.
     3. Ngoài ra bạn có thể bổ sung file CMakeLists.txt nếu bạn muốn thực thi nhiều chương trình trong cùng một project.
    
3. Như tên file, DeleteProject sẽ xoá đi tất tần tật trong dự án của bạn, nên hãy cân nhắc khi bạn muốn xoá 1 project.
  1. Ngoài ra thì mình cũng gắn sẵn dòng lệnh để xoá dòng add_subdirection(project_name) trong CMakeLists.txt ROOT nên bạn không cần lo đến việc đó đâu ( :)) chỉ lo khi bạn thêm dòng add_library thôi vì nếu có thì bạn phải xoá thủ công).

4. Tất nhiên, code mình vẫn lỏ và cần nhiều chỗ cải tiến nên có vấn đề gì thì hãy cho mình biết nhé :>         
