import turtle

t = turtle.Turtle()

turtle.Screen().bgcolor("yellow")
t.fillcolor("white")
t.shape("turtle")
t.begin_fill()

for i in range(80):
    t.up()
    t.fd(4+i)
    t.stamp()
    t.rt(15)
    t.down()
t.end_fill()
t.ht()
turtle.Screen().exitonclick()

