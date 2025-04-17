import random

n = 100000

cont = 0

for i in range (n):
    x = random.uniform(0, 2)
    y = random.uniform(0, 2)
    if ( ((x<1) and (y>1)) or ((x>1) and (y<1)) or ((y>1) and (y<=x)) ):
        cont += 1
        
perc = 100 * cont/n
print(perc)