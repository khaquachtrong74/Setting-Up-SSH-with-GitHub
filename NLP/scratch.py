import requests
import re
import ctypes
from bs4 import BeautifulSoup

lib = ctypes.CDLL("./libexample.so")
# khai báo kiểu dữ liệu mà hàm c++ sẽ nhận
lib.tlw.restype = ctypes.c_char_p
lib.tlw.argtypes = [ctypes.c_char_p]

# def tlw(a):
#     new_text = " "
#     for c in a:
#         if 'A' <= c <= 'Z':
#            new_text += chr(ord(c) + 32)
#     return new_text
url = "https://docln.net/truyen/19392-tin-buon-nguoi-ban-tho-au-ma-toi-nghi-la-stundere-suot-10-nam-lai-thuc-su-ghet-toi/c144507-chapter-1"
url1 = "https://doctruyenonl.com/tu-vong-truoc-gio-ta-nuoi-mot-cai-boss/chuong-1"
url2 = "https://baomoi.com/"
respone = requests.get(url1)

html_content = respone.text
soup = BeautifulSoup(html_content, "html.parser")#analys
paragraphs = soup.find_all("p")
prg = list()
a = "heLlo"
a_lw = lib.tlw(b"HelLo")
a_new = " "
# Chuỗi bytes cần giải mã
byte_string = b'pE\x8cV\xdc\x7f'

# Thử giải mã với một số encoding phổ biến
encodings = ['utf-8', 'ascii', 'latin-1', 'utf-16', 'utf-32']

print("Kết quả giải mã:")
for encoding in encodings:
    try:
        decoded = byte_string.decode(encoding)
        print(f"{encoding}: {decoded}")
    except UnicodeDecodeError:
        print(f"{encoding}: Không thể giải mã")

# Hiển thị dưới dạng hex
print("\nDạng hex:")
print(' '.join(f'{b:02x}' for b in byte_string))
# for i in paragraphs[1:-1]:
#     tmp = i.get_text()
#     tmp = tlw(tmp)
#     prg.append(tmp)
#     print(type(tmp))
#     print(type(a))
#     print(prg[0])
#     break
# print(soup.prettify)
