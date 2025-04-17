import turtle as t
t.speed(100)

def anel(cor,x,y,grossura,raio):
    t.penup()
    t.goto(x,y)
    t.width(grossura)
    t.pendown()
    t.pencolor(cor)
    t.circle(raio)
    t.penup()

anel("blue",-110,-50,5,50)
anel("black",0,-50,5,50)      
anel("red",110,-50,5,50)
anel("yellow",-55,-100,5,50)
anel("green",55,-100,5,50)

