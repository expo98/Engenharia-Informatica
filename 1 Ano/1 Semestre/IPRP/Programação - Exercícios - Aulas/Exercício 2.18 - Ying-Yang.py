import turtle as t
window = t.Screen()
t.speed(10)
t.hideturtle()


def esseCirculo(raio,x,y):
    t.penup()
    t.fillcolor("black")
    t.begin_fill()
    t.rt(90)
    t.goto(x-raio,y)
    t.pendown()
    t.circle(raio,-180)
    t.rt(180)
    t.circle(raio,180)
    t.circle(2*raio,-180)
    t.end_fill()
    t.penup()

def circulo(raio,x,y,cor):
    t.penup()
    t.fillcolor(cor)
    t.begin_fill()
    t.goto(x+(raio*1.5),y)
    t.pendown()             
    t.circle(raio)
    t.penup()
    t.end_fill()


raio=200

esseCirculo(raio,-raio,0)  
circulo(2*raio,-4*raio,0,"")
circulo(raio/8,raio/2,0,"white")
circulo(raio/8,4*raio,0,"black")



window.exitonclick()