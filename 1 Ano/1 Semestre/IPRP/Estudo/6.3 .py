l1 = [1,2,3,4,5]
l2 = ['a','b','c']

def alterna(lista1,lista2):
    lista_alternada =[]


    if len(lista1)>len(lista2):
        tamanho_maior=l1
        tamanho_menor=l2
    else:
        tamanho_maior=l2
        tamanho_menor=l1


    for i in range(len(tamanho_menor)):
        lista_alternada.append(lista1[i])
        lista_alternada.append(lista2[i])

print(alterna(l1,l2))