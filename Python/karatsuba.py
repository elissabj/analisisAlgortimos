#funcion que añade ceros al arreglo
def agregaCeros(cad_modificar, ceros, izq = True):
    for i in range(ceros):
        if izq:
            cad_modificar = '0' + cad_modificar
        else:
            cad_modificar = cad_modificar + '0'
    return cad_modificar

#funcion de karatsuba
def algortimoKaratsuba(x ,y):
    x = str(x)
    y = str(y)

    #casos base para la recursion
    if len(x) == 1 and len(y) == 1:
        return int(x) * int(y)
    if len(x) < len(y):
        x = agregaCeros(x, len(y) - len(x))
    elif len(y) < len(x):
        y = agregaCeros(y, len(x) - len(y))
    n = len(x)
    j = n//2

    #para cuando es impar 
    if (n % 2) != 0:
        j += 1    
    b_con_ceros = n - j
    a_con_ceros = b_con_ceros * 2
    a = int(x[:j])
    b = int(x[j:])
    c = int(y[:j])
    d = int(y[j:])
    
    #funcion recursiva del proceso
    a_con_c = algortimoKaratsuba(a, c)
    b_con_d = algortimoKaratsuba(b, d)
    k = algortimoKaratsuba(a + b, c + d)

    A = int(agregaCeros(str(a_con_c), a_con_ceros, False))
    B = int(agregaCeros(str(k - a_con_c - b_con_d), b_con_ceros, False))
    return A + B + b_con_d

x = int(input())
y =  int(input())

print(algortimoKaratsuba(x,y))