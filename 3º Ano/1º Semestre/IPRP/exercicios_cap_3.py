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


if __name__ == "__main__":

    p = (2,3)
    exercicio3_7(p)

    frase = ("Monty Python")
    exercicio3_15(frase)

    exercicio3_16(frase)