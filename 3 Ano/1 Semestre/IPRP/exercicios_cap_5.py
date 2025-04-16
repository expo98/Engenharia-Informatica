def exercicio5_6():
    for i in range(3):
        for j in range(1,3):
            print(i/j)

def exercicio5_7(palavra1,palavra2):

    if len(palavra1) != len(palavra2):
        print("Erro: Palavras não têm igual cumprimento")
        return
    
    total_letras = len(str(palavra1))
    letras_iguais = 0

    for i in range(total_letras):
        if palavra1[i] == palavra2[i]:
            letras_iguais += 1
    
    if letras_iguais/total_letras >= 0.9:
        print("{0} e {1} são palavras amigas".format(palavra1,palavra2))

    else:
        print("{0} e {1} não são palavras amigas".format(palavra1,palavra2))
        

def exercicio5_8(num):

    divisor_menor = num

    for i in range(num, 1 , -1):
        print("{0}".format(i))

        if num%i == 0:
            divisor_menor = i

    print("O divisor menor de {0} é {1}".format(num,divisor_menor))
    
def exercicio5_20(num): 
    a1=1
    a2=1
    
    print(a1,end=",")
    print(a2,end=",")
    while (a2 < num):
        a3= a2
        a2 = a1+a2
        a1 = a3
        if (a2 == num):
            print(a2,end="\n")
            print("O número {0} pertence à sequência fibonacci".format(num))
            return

        print(a2,end=",")
        
    print("\nO número {0} não pertence à sequência fibonacci".format(num))






if __name__ == "__main__":
    #exercicio5_6()
    #exercicio5_7("abcdefghij","bbbdefghij23")
    #exercicio5_8(18)
    exercicio5_20(46369)