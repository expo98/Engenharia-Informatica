import random
l1=[]
l2=[]

numero_lancamentos = input('Quantas vezes deseja lançar dois dados? ')
numero_lancamentos = int(numero_lancamentos)
for i in range(0,numero_lancamentos):
    l1.append(random.randint(0,6))
    l2.append(random.randint(0,6))
print(l1)
print(l2)
vezes_par = 0
for i in range(0,numero_lancamentos):
    if (l1[i] + l2[i]) %2 == 0:
        vezes_par = vezes_par +1
        
print ( "%.2f" % (100*vezes_par / numero_lancamentos),"%")
