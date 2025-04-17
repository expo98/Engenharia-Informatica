import turtle

turtle.shape("turtle")
turtle.Screen().bgcolor("yellow")
turtle.fillcolor("white")

def triangulo(lado):
        for i in range (3):
                turtle.forward(lado)
                turtle.lt(120)
                turtle.stamp()           
        
def figura(lado):
        for j in range (6): 
                triangulo(lado)
                turtle.lt(60)
                
figura(100)
