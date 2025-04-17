import random

vezes = 999999999999999999
cont = 0

for i in range (vezes):
    x = random.uniform(0, 1)
    y = random.uniform(0, 1)
    d = (x**2 + y**2)**0.5
    if (d<=1):
        cont += 1
        
estPI = cont/vezes * 4
print(estPI)