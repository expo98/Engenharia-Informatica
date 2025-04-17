
def divisor(numero):
    b=0
    for i in range(numero,1,-1):
        b +=1
        print (b)
        if numero%i ==0:
            a = i
    print("O divisor mais pequeno de", numero, "é", a)


divisor(46716903)
