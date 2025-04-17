n = int(input("Digite o número de linhas que deseja que a tabela tenha: ")) + 1
print ('Número\t\tQuadrado')
for i in range(1, n):
     print('%6d%18d' % (i, i**2))