def fibo (n):
    a = []
    while(len(a) <= n):
        a.append(0)

    a[0] = 1
    a[1] = 1
    for i in range(2, n+1): #como si index en 0
        a[i] = a[i-1] + a[i-2]
    return a[n] 

z = int(input())
print(fibo(z))
