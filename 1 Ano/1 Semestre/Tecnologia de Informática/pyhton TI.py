import serial
import turtle 

window = turtle.Screen()

ser = serial.Serial('/dev/tty.usbserial-1410', baudrate=9600, timeout=0.1)

smart = turtle.Turtle()
s=ser.readline().strip()

while(s!=b'X'):
    s=ser.readline().strip()
    smart.forward(10)
    if (s==b'R'):
        smart.right(10)
    elif (s==b'L'):
        smart.left(10)
window.exitonclick()

window.exitonclick()