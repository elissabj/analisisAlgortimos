mem = []
while(len(mem) <= 1000000):
    mem.append(-1)

def formasDeSubir (n):
    if n == 0:
        return 1
    if n < 0:
        return 0
    if(mem[n] != -1):
        return mem[n]
    caminos = 0
    for i in range(1, k+1):
        caminos += formasDeSubir(n-i)
    mem[n] = caminos
    return mem[n]

a = input().split()
n = int(a[0])
k = int(a[1])
res = formasDeSubir(n)
print(res)
