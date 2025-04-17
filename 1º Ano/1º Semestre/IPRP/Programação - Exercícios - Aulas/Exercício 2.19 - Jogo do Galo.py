import turtle as t
window = t.Screen()
t.hideturtle()
t.speed(10)
t.pensize(20)

def tabuleiro():
    for i in range (2): #Desenha o tabuleiro, primeiro as linhas horizontais (l.9-14) e depois as verticais (l.15-19)
        t.penup()
        t.goto((i*100)+50,-50)
        t.pendown()
        t.lt(90)
        t.fd(300)
        t.rt(90)
        t.penup()
        t.goto(-50,(i*100)+50)
        t.pendown()
        t.fd(300)
        t.penup()

    for i in range(3): #Desenha as coordenadas, primeiro as abcissas (l.22-27) e depois as ordenadas(l.28-33)
        t.penup()
        x = i * 100
        t.goto(x-5,300)
        t.pendown()
        t.write(i , font=("Comic Sans", 30, "normal"))
        t.penup()
        y = i * -120
        t.penup()
        t.goto(-100,190+y)
        t.pendown()
        t.write(i , font=("Comic Sans", 30, "normal"))
        t.penup()
        
def jogadas():
    for i in range (5):
            abcissaVermelho = int(input("Jogador 1 - Escolhe uma posição(x): "))
            ordenadaVermelho = int(input("Jogador 1 - Escolhe uma posição(y): "))
            t.penup()
            t.goto(abcissaVermelho*100, 200 -ordenadaVermelho*100)
            t.pencolor("red")
            t.pendown()
            t.fd(0)
            t.penup()

            abcissaVerde = int(input("Jogador 2 - Escolhe uma posição(x): "))
            ordenadaVerde = int(input("Jogador 2 - Escolhe uma posição(y): "))
            t.penup()
            t.goto(abcissaVerde*100, 200 - ordenadaVerde*100)
            t.pencolor("green")
            t.pendown()
            t.fd(0)
            t.penup()

    





tabuleiro()
jogadas()
window.exitonclick()