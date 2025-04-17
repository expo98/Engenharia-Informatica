import turtle
import random
turtle.hideturtle
turtle.speed(1)
turtle.bgcolor("white")
turtle.pencolor("black")

def frente():
    turtle.pd()
    turtle.fd(50)

def tras():
    turtle.rt(180)
    turtle.fd(50)

def esquerda():
    turtle.lt(90)
    turtle.fd(50)

def direita():
    turtle.rt(90)
    turtle.fd(50)


def tarta_genetico(adn):

    for i in range(0, len(adn),1):
        if adn[i] == 1:
            frente()
        if adn[i] == 2:
            tras()
        if adn[i] == 3:
            esquerda()
        if adn[i] == 4:
            direita()

def orientacao(numero_instrucoes):
    list=[]
    for i in range(numero_instrucoes):
        list.append(random.randrange(1,4))

    print (list)
    return list

    
tarta_genetico(orientacao(10))

turtle.Screen().exitonclick()