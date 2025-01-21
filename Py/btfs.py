from bs4 import BeautifulSoup
soup = BeautifulSoup("<p>Some<b>bad<i>HTML", features="lxml")
print(soup.prettify())
print("Tìm text 'bad' : " + soup.find(string='bad'))
print(soup.i)
print("thêm tag - chắc vậy")
soup = BeautifulSoup("<tag1>some<tag2/>bad<tag3>XML","xml")
print(soup.prettify())

