numeros=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
par=0
impar=0
for numero in numeros:
    if numero%2 ==0:
        par += numero
    else:
        impar += numero
print(par, impar)
