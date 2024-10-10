import turtle as t
import math as m
import random

def exercicio2_1():
    t.showturtle()
    for i in range(0,5):
        t.forward(100)
        t.right(144)

    t.hideturtle()
        
def exercicio2_2():
    t.showturtle()

    for i in range(0,25):
        t.forward(5+ i*5)
        t.right(144)

    t.hideturtle()

def exercicio2_3():
    t.showturtle()
    for i in range(0,15):
        t.right(random.random()*180) 
        t.forward(144)

    t.hideturtle()


if __name__ == '__main__':
    #exercicio2_1()
    #exercicio2_2()
    exercicio2_3()