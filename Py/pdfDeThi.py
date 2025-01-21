import PyPDF2

file = open('De-thi-fix.pdf','rb')
pdf_reader = PyPDF2.PdfReader(file)

for i in range(len(pdf_reader.pages)):
    print(pdf_reader.pages[i].extract_text())
