import PyPDF2

myfile = open('US_Declaration.pdf', mode='rb')
#Read file pdf
pdf_reader = PyPDF2.PdfReader(myfile)

print(pdf_reader.pages)#numPages

page_one = pdf_reader.pages[0]#getPage(0)


# print(page_one.extract_text())#extractText()

myText = page_one.extract_text()
myfile.close()

#Lấy Page 1 và bỏ vào file pdf mới
f = open('US_Declaration.pdf', 'rb')
pdf_reader = PyPDF2.PdfReader(f)
first_page = pdf_reader.pages[0]
pdf_writer = PyPDF2.PdfWriter()
pdf_writer.add_page(first_page) # addPage
pdf_output = open('MY_BRAND_NEW.pdf','wb')
pdf_writer.write(pdf_output)#write pdf_writer -> pdf_output
pdf_output.close()
f.close()

brand_new = open('MY_BRAND_NEW.pdf','rb')

pdf_reader = PyPDF2.PdfReader(brand_new)
print(len(pdf_reader.pages)) #1

f = open('US_Declaration.pdf', 'rb')

pdf_text = []
pdf_reader = PyPDF2.PdfReader(f)
for p in range(len(pdf_reader.pages)):
    page = pdf_reader.pages[p]
    pdf_text.append(page.extract_text())
    
f.close()
print(len(pdf_text))
for page in pdf_text:
    print(page)
    print('\n')
    
