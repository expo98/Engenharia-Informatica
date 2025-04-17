def encriptar(orig, chave):
    alfabeto = 'abcdefghijklmnopqrstuvwxyz ' 
    encrip = ' '

    for i in range(len(orig)):
        p = alfabeto.index(orig[i])
        pe = p + chave
        ipe = pe % len(alfabeto)
        cod = alfabeto[ipe]
        encrip = encrip + cod
    return encrip


def desencriptar(cript, chave):
    alfabeto = 'abcdefghijklmnopqrstuvwxyz ' 
    desencript = ' '

    for i in range(len(cript)):
        p = alfabeto.index(cript[i])
        pd = p - chave
        ipd = pd % len(alfabeto)
        desencript = desencript + alfabeto[ipd]
    return desencript

chave = 2 
orig = 'assim z'
encriptar = encriptar(orig, chave)
print(encriptar)
print(desencriptar(encriptar, chave))