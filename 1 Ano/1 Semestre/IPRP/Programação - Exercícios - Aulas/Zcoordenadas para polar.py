import math

x = float(input(" Introduza um valor de  x: "))
y = float(input(" Introfuza um valor de y: "))
cord = (x,y)

if x == 0 and y == 0:
    print("\nAs suas coordenadas são " + str(cord))
    print("\nAs suas coordenadas em polar são (0,0)")
    
else:
    print("\nAs suas coordenadas são " + str(cord))
    r = math.sqrt(x**2 + y**2)
    c = y/r
    ang = math.asin(c)
    d = (180 / math.pi)
    graus = ang * d
    escolha = int(input("\nQuer os ângulos em graus(1) ou radianos(2) ?"))
    if escolha == 1:
        cord2 = ("{:.2f}".format (r),"{:.2f}".format (graus))
        print("\nAs coordenadas em polar são " + str(cord2))
        
    else:
        cord3 = ("{:.2f}".format (r),"{:.2f".format (d))
        print("\nAs coordenadas em polar são " + str(cord1))
        
        