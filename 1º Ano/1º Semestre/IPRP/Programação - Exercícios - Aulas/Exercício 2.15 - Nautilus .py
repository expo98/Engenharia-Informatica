import turtle as t
t.speed(10000)
def quadrado(lado):
    for i in range(4):
        t.forward(lado)
        t.lt(90)

def nautilus(lado,n):
    for j in range(n):
        quadrado(lado)
        t.lt(4)
        lado = lado + n*0.25
nautilus(10,50)