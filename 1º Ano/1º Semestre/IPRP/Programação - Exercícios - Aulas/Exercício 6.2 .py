lst = [1,4,7,9,3,2,8,5,6]

def par_impar(lista):
    a=0
    b=0
    for i in range(0,len(lista)):
        if (lst[i]%2)== 0:
            a= a + lista[i]
        else:
            b= b + lista[i]
    print("("+str(a)+","+str(b)+")")

par_impar(lst)
