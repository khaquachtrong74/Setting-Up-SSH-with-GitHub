from bs4 import BeautifulSoup
import newspaper as nsp
import string
import re
from collections import Counter
# function giúp tách từ vựng
def dataVocab(text):
    wordsSet = set()
    text = str(text)
    text = text.lower()
    unwanted_chars = string.punctuation + '"“”-+=.;' 
    newText = re.sub(f'[{re.escape(unwanted_chars)}]+',' ',text)
    words = newText.split()
    for c in words:
        wordsSet.add(c)
    # trả về tập set từ vựng và số lượng của nó
    return wordsSet, len(wordsSet)

def dataVocab2(text):
    # dùng biểu thức chính quy
    words = re.findall(r'\b\w+\b', text)
    # Sử dụng Counter để đếm số lần xuất hiện
    word_counts = Counter(words)
    # Chuyển đổi sang định dạng yêu cầu
    result = {word: count for word, count in word_counts.items()}
    return result # return dict

url = input()
vocabDict = dict()
htmlText = nsp.Article(url, memoize_articles = False)
htmlText.download()
htmlText.parse()
# Nối các phần tử bằng ký tự xuống dòng
text = dataVocab(htmlText.text)
print(type(text))
set_list = list(text)
#print(set_list)
#setString = str()
#for word in set_list:
    #print(type(str(word)))
    
#    setString += '\n' + str(word)
#with open('vocab.txt','w', encoding='utf-8') as f:
#    f.write(setString)
#print("da luu thanh cong")



