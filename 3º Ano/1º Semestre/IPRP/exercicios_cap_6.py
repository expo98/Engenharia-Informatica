import turtle
import random


def exercicio6_6():
    lista_num = [1,2,3,4,5]
    nova_lista = []

    for i in range(len(lista_num)):
        nova_lista.append(lista_num[i])
        for j in range(0,i):
            nova_lista[i] += lista_num[j]

    print(nova_lista)

def exercicio6_7():
    imagem = [[0,1,0],[1,1,1],[0,1,0]]

    for i in range(len(imagem)):
        for j in range(len(imagem[0])):
            if imagem[i][j] == 1:
                imagem[i][j] = 0
                

            elif imagem[i][j] == 0:
                imagem[i][j] = 1

    
    print(imagem)

def exercicio6_8():
    imagem = [[0,1,2],[1,1,0],[0,1,0]]
    
    nova_imagem = [[0 for _ in range(len(imagem))] for _ in range(len(imagem[0]))]

    for i in range(len(imagem)):

        for j in range(len(imagem[0])):
            nova_imagem[j][len(imagem)-1-i] = imagem[i][j]
    
    for i in range(3):
        print(nova_imagem[i])

def main_tarta(n):
    tartaruga = turtle.Turtle()
    tartaruga.left(90) # vira para inciialmente em cima
    comandos = gera_comandos(n)
    navega(comandos, tartaruga)
    turtle.exitonclick()

def gera_comandos(n):

    comandos = ("w","a","s","d")

    lista_comandos = []

    
    for i in range(n):
        rand =  random.randint(0,3)
        lista_comandos.append(comandos[rand])

    return lista_comandos

def navega(comandos, tartaruga):

    for i in range(len(comandos)):
        
        if comandos[i] == "w":
            tartaruga.forward(30)
            print("Forward")

        elif comandos[i] == "a":
            tartaruga.left(90)
            tartaruga.forward(30)
            print("Left")

        elif comandos[i] == "s":
            tartaruga.left(180)
            tartaruga.forward(30)
            print("Backwards")


        elif comandos[i] == "d":
            tartaruga.left(-90)
            tartaruga.forward(30)
            print("Right")


def exercicio6_16():

    vogais = "AEIOUaeiou"
    dicionario = dict()

    frase = "agora e que vao ser elas, Ai, Ai!"

    for i in range(len(frase)):
        for vogal in vogais:
            if frase[i] == vogal:
                if vogal not in dicionario:
                    dicionario[frase[i]] = [i]
                else:
                    dicionario[frase[i]].append(i)

    print(dicionario)

def exercicio6_17():
    dicionario = {"joao":10,"pedro":18, "tiago":13,"luis":18}

    dicionario_invertido = dict()

    for key in dicionario:
        if dicionario[key] in dicionario_invertido:
            dicionario_invertido[dicionario[key]].append(key)
        else:
            dicionario_invertido[dicionario[key]] = [key]

    print(dicionario_invertido)

            



if __name__ == "__main__":
    #exercicio6_6()
    #exercicio6_7()
    #exercicio6_8()
    #main_tarta(5)
    #exercicio6_16()
    exercicio6_17()