#Soma cumulativa


lista1=[1,2,3,5,6,7]
lista2=[]
for i in range(len(lista1)):
    if i ==0:
        lista2.append(lista1[i])
    else:
        lista2.append(lista1[i]+lista2[i-1])
    

print(lista2)
