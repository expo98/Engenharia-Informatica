def ler_algures(nome, pos, num):
    f=open(nome, 'r')
    f.seek(pos)
    s = f.read(num)
    return s

print(ler_algures('omeuficheiro.txt', 10, 10))