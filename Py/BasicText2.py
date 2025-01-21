#open test.txt
#get path : in terminal text> pwd
def line():
    print("____________________________")

#cách mở 1 file ra
myfile = open("test.txt")
line()
print(myfile)
#cách đọc file hoạt động như 1 con trỏ từ đầu tới đuôi vậy, nên khi thực hiện 1 làn xong thì dừng
myfile.read()
#Khắc phục bằng cách đưa con trỏ về 0 để chuẩn bị cho lần đọc tiếp theo
myfile.seek(0)
line()
print(myfile.read())
myfile.seek(0)

content = myfile.read()
line()
print(content)
myfile.close()

myfile = open('test.txt')
line()
print(myfile.readlines())
myfile.seek(0)
mylines = myfile.readlines()
line()
for line in mylines:
    print(line.split()[0]) #split sẽ cho tách nguyên từ thay vì 1 kí tự

#default mode = read , mode = w+ ghi đè
myfile = open('test.txt',mode='w+')
print(myfile.read()) # empty
myfile.write('MY BRAND NEW TEXT')
myfile.seek(0)
print(myfile.read())
myfile.close()
#append
myfile = open('test.txt', mode='a+') #can create a new txt if it hasn't there
myfile.write("MY LITTLE SUBJECT IS 10 plus")
myfile.close()


myfile = open('test.txt')
print(myfile.read())
myfile.close()
#Với cái này khi chạy xong thì nó sẽ tự động close lại file
with open('test.txt','r') as mynewFile:
    myvariable = mynewFile.readlines()
print(myvariable)

