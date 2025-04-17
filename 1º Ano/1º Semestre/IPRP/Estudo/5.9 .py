import random

def dados(numero_lancamentos):
    lancamentos = []
    for i in range(numero_lancamentos):
        lancamentos.append(random.randrange(1,6))

    n_par=0
    for i in lancamentos:
        if i%2 ==0:
            n_par +=1
    
    percentagem_par = 100* (n_par / numero_lancamentos)

    return round(percentagem_par,2)


print(dados(201), "%")

    

