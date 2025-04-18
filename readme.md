# Các bước để push code thông qua terminal
Nguồn tham khảo: [docs.github](
https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent),
[stackoverflow](https://stackoverflow.com/questions/72760526/github-error-key-is-invalid-you-must-supply-a-key-in-openssh-public-key-forma
)

Bạn không thể dùng git trên linux, bạn bối rối!, bạn không biết phải làm gì cả :(. Nếu thế hãy vào đây và thực hiện từng bước dưới nhé

1. Ta mở terminal và gõ dòng lệnh sau để tạo ssh key 
``` Sh
ssh-keygen -t ed25519 -C "your_Email@example.com"
```
Trường hợp hệ thống không hỗ trợ giải thuật Ed25519 thì ta dùng.
``` Sh
ssh-keygen -t rsa -b 4096 -C "Your_email@example.com" 
```
2. Truy cập vào trang github cá nhân, vào settings -> `SSH and GPG keys` -> chọn `New SSH key`.

3. Lấy ssh key public trên máy (pub ở đây là public). 
```Sh
cat ~/.ssh/nameYourKey.pub
```
- Thường nameYourKey sẽ là `id_rsa.pub`
4. Sau đó copy hết toàn bộ, và đem nó bỏ vào key ở bước (2). 
5. Kiểm tra kết nối với lệnh

```Shell
ssh -T git@github.com
```

XD ýe, tới đây rồi thì chỉ có push ngon lành thôi.

## Thay đổi git remote nếu cần.

```Sh
git remote -v
```
  
1. nếu là url thì bạn hãy dùng lệnh 

```Shell
git remote set-url origin git@github.com:username/repo.git
```
2. Nếu chưa có thì (lệnh này nhớ không rõ, nếu sai thì bạn tự sửa nhé!)
```Shell
git remote add origin git@github.com:username/repo.git 
```

## Đọc thêm tài liệu tại `docs.github` hoặc `stackoverflow`
