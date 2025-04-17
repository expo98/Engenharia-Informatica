import math

n = 10000000000000

dif = 1
perc = 0.0000000000001
i = 0
acum = 0 

while (dif > perc):
    antigo = acum
    p = 1/math.factorial(i)
    acum += p
    dif = acum - antigo
    i += 1

print ('Valor calculado: ', acum, ' Erro: ', dif)