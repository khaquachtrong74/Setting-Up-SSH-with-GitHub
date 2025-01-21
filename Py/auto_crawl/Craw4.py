#soha
import pandas as pd
from newspaper import build
from newspaper import Article
import csv
# Define the URL of the news website
cnn_paper = build('https://soha.vn/bao-dan-tri.html',language='vi')
Source =[]
Date=[]
Content=[]
num = 0
# Iterate through the articles
print("So bai viet")
for articles in cnn_paper.articles:
    article = Article(articles.url, request_timeout=100,language='vi')
    article.download()
    try:
        article.parse()
        if article.publish_date == None:
            continue
        else:
            num = num + 1
            Source.append(article.url)
            Content.append(article.meta_data["description"])
            Date.append(article.publish_date)
        print(num)
    except Exception as e:
        pass
df = pd.DataFrame({
    'Date': Date,
    'Content': Content,
    'Source': Source
})
df.to_csv('data_soha.csv',mode='a',header=False,index=False)


