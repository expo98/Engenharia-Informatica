import serial
import turtle 

window = turtle.Screen()

s =""

ser = serial.Serial('/dev/tty.usbserial-1410', baudrate=9600, timeout=0.1)

smart= turtle.Turtle()
cmd=ser.readline().strip().decode()


while (True):
    cmdd=ser.readline().strip().decode()
    p=cmd.split(":")

    if(len(p)==2):
        c=p[0]
        v=p[1]

        if (((v[0]=='-') and (v[1:].isdigit()) or (v.isdigit()))):
            v=(int(v)/512.0)

            if (c=="X"):
                smart.left(10*v)
            
            if (c=="Y"):
                smart.forward(10*v)

window.exitonclick()