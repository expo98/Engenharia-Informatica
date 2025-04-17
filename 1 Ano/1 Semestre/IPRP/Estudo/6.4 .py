def conta_menores(numero,lista_numeros):
    contagem_menores=0
    for item in lista_numeros:
        if item < numero:
            contagem_menores +=1

    return contagem_menores

print(conta_menores(5,[2,8,6,5,3,2]))