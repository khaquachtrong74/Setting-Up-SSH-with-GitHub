text = "The phone number of the agent is 408-555-1234. Call soon!"
"phone" in text

#true

import re
pattern = "phone"
re.search(pattern, text)
myMatch = re.search(pattern, text)
print(myMatch)
print(myMatch.span())
print(myMatch.start())
print(myMatch.end())
text = "my phone is a new phone"
match = re.search(pattern, text)
print(match.span())

all_matches = re.findall("phone",text)
print(all_matches) #or len ()

for tp in re.finditer("phone",text):
    print(tp.span())
    
text = "my telephone number is 777-555-1234"
print(text)

#regular string
pattern = r'\d\d\d-\d\d\d-\d\d\d\d'
phone_number = re.search(pattern, text)
print(phone_number)
print(phone_number.group())
pattern = r'\d{3}-\d{3}-\d{4}'
pn = re.search(pattern, text)
print(pn.group())