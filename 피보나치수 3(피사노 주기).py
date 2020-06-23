x=int(input())
p=1500000
y=x%p
tmp=0
tmp2=1
result=0

for i in range(2,y+1):
    result=tmp +tmp2
    tmp = tmp2 % 1000000
    tmp2 = result %1000000

if y==0:
    print(0)
elif y == 1:
    print(1)
elif y == 2:
    print(1)
else:
    print(result%1000000)