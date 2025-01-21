from bs4 import BeautifulSoup
import re, requests
import newspaper

def vocabSet(obj):
    vocab = set()
    for c in obj:
        vocab.add(c)
    return vocab
def totalWords(obj):
    words = obj.split()
    totalWords = len(words)
    vocab = vocabSet(words)
    return totalWords, words, vocab
#def tokenize(obj):
    

#url = "https://truyenfull.io/can-cu-nong-hoc-so-chin/chuong-1/?utm_source=truyenfull_io&utm_campaign=truyenfullio_boxhothome"
def sumAll(url):

    article = newspaper.Article(url, memoize_articles = True)
    article.download()
    article.parse()
    soup = BeautifulSoup(article.html, 'html.parser')
    content = soup.find('div', {'class':'pd-lr-30'}).get_text()
    #thuật toán dùng để xác định tần suất hiện các từ trong nội dung
    #đánh giá theo tần suất xuất hiện (tfidf)
    docWords = re.sub(r'[^a-zA-Z\s]','',content).lower()
    size, words, vocab = totalWords(content.lower())
    return size, words, vocab, len(vocab)

if __name__ == '__main__':

    urls = ["https://nhasachmienphi.com/doc-online/tuoi-tho-du-doi-306812"]
    #for index in range(1, 300):
   #     urls.append(f"https://truyenfull.io/duong-chuyen/chuong-{index}/")
    realSize = 0
    realVocab = set()
    
    size, words, vocab, sizeVocab = sumAll(urls[0])
    realSize += sizeVocab
    for char in vocab:
        realVocab.add(char)
    print(len(realVocab))
    
    print(realSize)
    print(words)
    print(vocab)
    
