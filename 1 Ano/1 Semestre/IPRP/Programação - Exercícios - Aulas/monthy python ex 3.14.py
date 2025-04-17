print("Introduz qualquer coisa")

palavra = str(input())

print("Introduz o número inteiro positivo pelo qual queres que a palavra seja igualmente cortada")

corte = int(input())

while corte < 0 :
    print("Introduz o número inteiro positivo pelo qual queres que a palavra seja igualmente cortada")
    
    corte = int(input())    

comprimento_palavra = len(palavra)

while corte > len(palavra):
    print("Introduz o número inteiro positivo, menor que o número de caracteres daquilo que introduziste previamente, pelo qual queres que a palavra seja igualmente cortada")
    
    corte = int(input())      

palavra_dividida = len(palavra)//corte


print([ palavra[i:i+palavra_dividida] for i in range(0, comprimento_palavra, palavra_dividida) ])
