idades = [15, 16, 13, 17, 18, 18, 32, 20, 21]

#Alínea a)
print("Alínea a)")
print(len(idades))



#Alínea b)
print("Alínea b)")
for i in idades:
    print(i)

#Alínea c)
print("Alínea c)")
for i in range( len(idades)-1 , -1, -1):
    print(idades[i])

#Alínea d)
print("Alínea d)")
for i in range(1,len(idades)-1):
    print(idades[i])

#Alínea e)
print("Alínea e)")
valor_maximo = None
valor_minimo = None
for number in idades:
    if valor_maximo is None or valor_maximo < number:
        valor_maximo = number
print("O valor máximo é ", valor_maximo)
for number in idades:
    if valor_minimo is None or valor_minimo > number:
        valor_minimo = number
print("O valor mínimo é ", valor_minimo)

#Alínea f)
print("Alínea f)")
a=0
for i in range(0,len(idades)):
    a = a + idades[i]
print (a)