import math as m
def comprimento_escada(altura,angulo_graus):
    angulo_radianos = m.pi * angulo_graus * (180**(-1))
    comprimento = altura * (m.sin(angulo_radianos))
    return comprimento


print(comprimento_escada(10,60))
