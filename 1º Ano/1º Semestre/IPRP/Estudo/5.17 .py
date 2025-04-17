"""def padrao_a(numero):
    contagem=[]
    for i in range(1,numero):
        contagem.append(i)

    for i in range(1,len(contagem)):
       print(contagem[0:i])

def padrao_b(numero):
    contagem=[]
    for i in range(1,numero):
        contagem.append(i)

    for i in range(1,len(contagem)):
        print(contagem[0:i])
        """

def padrao_a(n):
    for i in range(1,n+1):
        for j in range(1,i+1):
            print(j,end=' ')
        print("")

def padrao_b(n):
    for i in range(1,n+1):
        for j in range(1,n-i+2):
            print(j,end=' ')
        print("")    
    
def padrao_c(n):
    for limite in range(1,n+1): #limite por cada linha
        espacos="   "*(n-limite)
        print(espacos,end='')            
        for j in range(limite,0,-1):
            #print(j,end=' ')
            print("{:>2d}".format(j),end=' ')
        print()