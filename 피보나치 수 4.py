x=int(input())
tmp=1
tmp2=1
result=0

if x == 1:
    print(1)
if x == 2:
    print(1)

for i in range(2, x) :
    result=tmp+tmp2
    tmp=tmp2
    tmp2=result

if x!=1 :
    if x!=2 :
     print(result)