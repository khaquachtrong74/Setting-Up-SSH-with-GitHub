# Các bước để push code thông qua terminal
Nguồn tham khảo: {
https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent
,
https://stackoverflow.com/questions/72760526/github-error-key-is-invalid-you-must-supply-a-key-in-openssh-public-key-forma

}
1. Vì thông qua linux (nói chung) thì github không còn hỗ trợ cho việc dùng URL nữa (13 tháng 8 năm 2021, github đã loại bỏ hỗ trợ xác thực mật khẩu) (Thật ra cái này không chắc nhưng vì làm quá phức tạp và không thành công). Cho nên ta sẽ hướng tới việc dùng ssh thay vì url

2. Ta mở terminal và gõ
``` Sh
ssh-keygen -t ed25519 -C "your_Email@example.com"
```
    - Trường hợp hệ thống không hỗ trợ giải thuật Ed25519 thì ta dùng.
``` Sh
ssh-keygen -t rsa -b 4096 -C "Your_email@example.com" 
```
3. Nó sẽ tạo ra SSH key, bước tới cứ ấn Enter cho next qua cũng được. Có thể tham khảo qua nguồn 1.


5. Lúc này ta vào trang github của mình, vào settings -> "SSH and GPG keys". Chọn New SSH key.

6. Quay lại với terminal, vì bước này khá nhiều người bị lỗi (mình thì quằn chỗ này gần 1 tiếng). Để tránh việc bị nhầm thì thường SSH key sau khi được tạo ra sẽ nằm tại ~/.ssh/nameYourKey.pub (pub ở đây là public - và mình sẽ cần nó). 
```Sh
cat ~/.ssh/nameYourKey.pub
```
6. Sau đó copy hết toàn bộ, và đem nó bỏ vào key ở bước (4). 
7. Nếu không báo lỗi thì chúc mừng bạn xong được 1 nửa (nếu không thì bạn có thể đọc thêm tài liệu của github hoặc mò trên stackoverflow!)
8. Bạn có thể kiểm tra kết nối với lệnh
```Shell
ssh -T git@github.com
```
    Bạn có thể thấy vài cảnh báo nhưng cứ ấn 'yes' đi.

9. Sau đó bạn hãy về với workspace của mình (nơi mà muốn đẩy lên repo). Ta có thể kiểm tra xem git remote của bạn hiện tại là url hay ssh. Ta có thể kiểm tra thông qua lệnh
```Sh
git remote -v
```
    9.1 nếu là url thì bạn hãy dùng lệnh 
```Shell
git remote set-url origin git@github.com:username/repo.git
```
    9.2 Nếu chưa có thì (lệnh này nhớ không rõ, nếu sai thì bạn tự sửa nhé!)
```Shell
git remote origin git@github.com:username/repo.git 
```

XD ýe, tới đây rồi thì chỉ có push ngon lành thôi. 

