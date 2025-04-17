import random
def soma_de_dados(lancamentos):
    lancamento_dado_1=[]
    lancamento_dado_2=[]
    soma_lancamentos=[]
    par = 0

    
    for i in range(lancamentos):
        lancamento_dado_1.append(random.randint(1,6))
        lancamento_dado_2.append(random.randint(1,6))

    #Faz a soma dos lançamentos do dado1 e dado2 e adiciona-os a uma lista
    for i in range(lancamentos):
        soma_lancamentos.append(lancamento_dado_1[i] + lancamento_dado_2[i])

    #Verifica se a soma dos lancamentos é par
    for soma in soma_lancamentos:
        if soma%2==0:
            par +=1

    return round(100*(par/lancamentos),2)

print(soma_de_dados(3530102),"%")
    

