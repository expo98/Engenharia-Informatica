#MINHA SOLUÇÃO
def posicoes(frase):
    vogais={
        "A":[],
        "E":[],
        "I":[],
        "O":[],
        "U":[],
        "a":[],
        "e":[],
        "i":[],
        "o":[],
        "u":[]
    }
    for i in range(len(frase)):
        for c,v in vogais.items():
            if frase[i] == c:
                v= v.append(i)
    return vogais

print(posicoes("agora e que vao ser elas, Ai, Ai!"))

#SOLUÇAO PROFESSOR
def cria_dic(s):
    d = {}
    for i,v in enumerate(s):
        if v in 'aeiouAEIOU':
            # adicionar i à lista de valores da chave v]
            #d.setdefault(v, [])
            #d[v] = d[v] + [i]

            d[v] = d.setdefault(v, []) + [i]
    return d

