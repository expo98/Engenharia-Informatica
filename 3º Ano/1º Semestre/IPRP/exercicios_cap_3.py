import math 

def exercicio3_7(p):
    H = 0
    for i in range(2):
       H += p[i] *  math.log2(p[i])

    H *= -1

    print("H = ", H)

def exercicio3_15(frase):
    i = 1
    while i <= len(frase):
        print(frase[:i+1])
        i+=1

def exercicio3_16(frase):
    i = len(frase)
    while i > 0:
        print(frase[i-1:])
        i -= 1


def codificar(frase):
    alfabeto = "abcdefghijklmnopqrstuvwxyz "
    distancia = 2
    frase_codificada = ""

    for i in range(len(frase)):
        for j in range(len(alfabeto)):
            if frase[i] == alfabeto[j]:
                frase_codificada += alfabeto[(j+distancia)%27]
                break

    print(frase_codificada)

def descodificar(frase_codificada):
    alfabeto = "abcdefghijklmnopqrstuvwxyz "
    distancia = 2
    frase_descodificada = ""

    for i in range(len(frase_codificada)):
        for j in range(len(alfabeto)):
            if frase_codificada[i] == alfabeto[j]:
                novo_indice =   (j -distancia) % len(alfabeto)
                frase_descodificada += alfabeto[novo_indice]
                break

    print(frase_descodificada)

if __name__ == "__main__":

    """p = (2,3)
    exercicio3_7(p)

    frase = ("Monty Python")
    exercicio3_15(frase)

    exercicio3_16(frase)"""

    codificar("abc")
    descodificar("cde")