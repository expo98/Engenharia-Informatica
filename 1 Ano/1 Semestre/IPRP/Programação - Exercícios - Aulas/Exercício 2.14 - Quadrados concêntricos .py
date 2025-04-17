import turtle as t

t.speed(1000)

def quadrado(lado):
    for i in range (4):
        t.fd(lado)
        t.lt(90)

def concentricos(lado, n):
    for j in range(1,n):
        t.penup()
        t.goto( - lado/2,- lado/2)
        t.pendown()
        quadrado(lado)
        lado = lado + n 
        
concentricos(10, 20)

