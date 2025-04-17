def area_triangulo(a,b,c):
    s= (a+b+c)*(1/2)
    area= ((s*(s-a)*(s-b)*(s-c))**(1/2))

    return area

print(area_triangulo(10,10,10))
