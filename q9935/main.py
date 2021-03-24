import re

target = input()
explode_string = input()
p = re.compile(explode_string)
a = target.replace(explode_string, "")
while p.search(a) != None:
    a = a.replace(explode_string, "")

if(a):
    print(a)
else:
    print("FRULA")
