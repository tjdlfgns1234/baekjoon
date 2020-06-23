import math

#int/int : float 반환 나눗셈, int//int: int 반환 나눗셈

def Combination(n,k):
    result=1
    tmp=1
    tmp2=1
    for i in range(n-k+1,n+1):
        tmp=tmp*i;
    for j in range(1,k+1):
        tmp2=tmp2*j;
    result = (int(tmp) // int(tmp2)) % 10007
    return result;

n,k=input().split()
n=int(n)
k=int(k)
print(int(Combination(n,k)))