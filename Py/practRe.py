import re
import string

text = '''
    Beautiful Soup's support for Python 2 was discontinued on December 31, 2020: one year after the sunset date for Python 2 itself. From this point onward, new Beautiful Soup development will exclusively target Python 3. The final release of Beautiful Soup 4 to support Python 2 was 4.9.3.

'''
def cleanText(txt):
    partern = string.punctuation + ','
    return re.sub(f'[{re.escape(partern)}]+','',txt)
vocabs = ""
with open("vocab.txt",'r',encoding='utf-8') as f:
    newText = cleanText(str(f.readlines()))
    vocabs = re.split("\s",str(newText))
print(vocabs)
vocabs = set(vocabs)
text = input()
newText = list(re.split("\s",cleanText(text).lower()))


for vocab in newText:
    vocabs.add(vocab)

print(vocabs)
print("Số lượng từ ")
print(len(vocabs))

vocabs = list(vocabs)
txt = str()
for word in vocabs:
    txt += word + " "
print(vocabs)
print(type(vocabs))
with open("vocab.txt",'w',encoding='utf-8') as f:
    f.write(txt)
