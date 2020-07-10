a, b = map(int, input().split())
check = [True]*(b-a+1)
n = 2
count = 0
while n*n <= b:
    square = n*n
    n = n+1

    if a % square == 0:
        start = a

    else:
        start = a - (a % square) + square

    k = 0
    while start + square * k <= b:
        check[start + square * k - a] = False
        k = k + 1

for i in range(0, b - a + 1):
    if not check[i]:
        count = count + 1

print(len(check)-count)



