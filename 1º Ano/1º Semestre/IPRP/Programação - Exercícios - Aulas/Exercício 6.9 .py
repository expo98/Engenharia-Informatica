import random
import turtle

def gera_comandos(n):
    comandos=[]
    for i in range(n):
        a = random.randint(1,3)
        comandos.append(a)
        print(comandos)
    return comandos

def navega(direction_list,turtle):
    turtle.pd()
    for i in range(0,len(direction_list)):
        if direction_list[i]==1:
            turtle.lt(90)
            turtle.fd(50)
            turtle.rt(90)
            print("left turn")
            #turtle.rt(0)
        if direction_list[i]==2:
            turtle.rt(90)
            turtle.fd(50)
            turtle.lt(90)
            print("right turn")
           # turtle.lt(0)
        if direction_list[i]==3:
            turtle.fd(50)
            print("forward")


def main_tarta(n):
    tartaruga = turtle.Turtle()
    comandos = gera_comandos(n)
    navega(comandos,tartaruga)
    turtle.exitonclick()


main_tarta(5)