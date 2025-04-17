import turtle as t

window = t.Screen()
t.Screen().bgcolor("yellow")
t.penup()
t.speed(10)

def circuloMaior(raio):
     t.pencolor("black")
     t.fillcolor("black")
     t.begin_fill()
     t.goto(0,-raio)
     t.pendown()
     t.circle(raio)
     t.penup()
     t.goto(0,0)
     t.end_fill()
     
def triangulos(raio):
     t.pencolor("yellow")
     t.fillcolor("yellow")
     t.pendown()
     for j in range (3):
          t.begin_fill()
          for i in range (3):
               t.forward(1.5*raio)
               t.lt(120)
          t.end_fill()
          t.lt(120)
     t.penup()

def circuloMenor(raio):
     t.width(10)
     t.pencolor("yellow")
     t.fillcolor("black")
     t.begin_fill()
     t.goto(0, - raio/4)
     t.pendown()
     t.circle(raio/4)
     t.end_fill()
     t.penup()
     
def radioactividade(raio):
     circuloMaior(raio)
     triangulos(raio)
     circuloMenor(raio)
     t.hideturtle()


radioactividade(250)
window.exitonclick()