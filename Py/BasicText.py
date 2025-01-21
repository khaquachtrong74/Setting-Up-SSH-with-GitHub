def line():
    print("________________________________")
person = "jose"
print("myname is {}".format(person))
#fstring 
print(f"myname is {person}")

#dictionary
d = { 'a':123, 'b':456 }
print(f"My numb is {d['a']}")
#list
l = (123,456,789)
print(f"My numb is {l[2]}")

library = [('Author','Topic','Pages'),
           ('DTK', "Ragitingb", 123),
           ("DetK", "Hold on heart break down", 222)
           ,("Los", "Being hope death", 511)]

#LOOP
for book in library:
    print(book)
line()
for author, topic, pages in library:
    print(f"{author} , {topic}, {pages}")
    
line()
#Insert space
for author, topic, pages in library:
    print(f"{author:{10}} {topic:{30}} {pages:.>{10}}")
    
line()
from datetime import datetime
today = datetime(year=2019, month=2, day=28)
#strftime.org
#format time
print(f"{today:%B %d, %Y}")
today