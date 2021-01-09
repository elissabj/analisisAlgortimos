
def nuevaMatriz(n, m):
    matriz = []
    for i in range (n):
        a = [-1]*m
        matriz.append(a)
    return matriz

lista_listas = nuevaMatriz (1200,1200)

def lcs (i, j):
    if i == 0 or j == 0:
        return 0
    if(lista_listas[i][j] != -1):
        return lista_listas[i][j]

    lista_listas[i][j] = lcs (i-1, j-1) + 1
    if(a[i-1] == b[j-1]):
        return lista_listas[i][j]
    
    lista_listas[i][j] = max (lcs(i, j-1), lcs(i-1, j))
    return lista_listas[i][j]


a = input()
b = input()
print(lcs(len(a),len(b)))

