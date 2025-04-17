l1=[1,2,3]
l2= ['a','b','c']

def alterna(lista1,lista2):
    lista_alterna =[]    
    for i in range (0,len(lista1)):
        lista_alterna.append(lista1[i])
        lista_alterna.append(lista2[i])
    print(lista_alterna)

alterna(l1,l2)