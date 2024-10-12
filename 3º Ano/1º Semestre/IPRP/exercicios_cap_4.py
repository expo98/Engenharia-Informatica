def exercicio4_12(numeros):
    print(""*len(str(numeros))+ "Número          " + ""*len(str(numeros)) +"Quadrado")
    
    for i in range(1, numeros+1):
        print("     {0:4d}         {1:5d}".format(i,i*i))



def exercicio4_14(num):
    print("Tabuada do número %d" %(num))
    print("--------------------")

    for i in range(1,11):
        print("{0:2d}   x   {1:2d} =   {2:2d}".format(num, i, i*num))


def exercicio4_15(nome):
    acronimo = ""
    acronimo+= nome[0]

    for i in range(len(nome)):
        if nome[i] == " " and i != len(nome)-1:
            acronimo += nome[i+1]

    print(acronimo)



def exercicio4_19():
    lista = [[1,2,3],[4,5,6],[7,8,9],[10,11,12]]

    for i in range(len(lista)):
        for j in range(len(lista[0])):
            print("({0:1d},{1:1d}) : {2:2d}".format(i,j,lista[i][j]), end=" ")
        print("")

def exercicio4_20():

    dias_ano = 365
    freq_nascimentos = int(input("Introduza a frequencia de nascimentos (minutos): "))
    freq_falecimentos = int(input("Introduza a frequencia de falecimentos (minutos): "))
    freq_emigracao = int(input("Introduza a frequencia de emigração (minutos): "))
    pop_inical = int(input("Introduza a população inicial: "))

    min_ano = 365*24*60

    pop_final = pop_inical + (min_ano/freq_nascimentos) - (min_ano/freq_falecimentos) - (min_ano/freq_emigracao)
    print("Resumo dos dados:")
    print("----------------")
    print("Frequẽncia de mortes: {0}".format(freq_falecimentos))
    print("Frequência de nascimentos: {0}".format(freq_nascimentos))
    print("Frequência de emigração: {0}".format(freq_emigracao))
    print("----------------")
    print("Estimativa:")
    print("----------------")
    print("A população ao fim de uma ano: {0}".format(pop_final))


if __name__ == "__main__":
    #exercicio4_12()
    exercicio4_14(7)
    exercicio4_15("Random Access Memory")
    exercicio4_19()
    exercicio4_20()
