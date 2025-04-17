str= 'agora e que vao ser elas, Ai, Ai!'

def cria_dic(s):
    d ={}
    for i in range(len(s)):
        if s[i] in 'aeiouAEIOU':
            '''
            adicionar i à lista de valores da chave s[i]
            d.setdefault(s[i],[])
            d[s[i]] = d[s[i]] + [i]
            Subsituida pela linha 12                          '''
            d[s[i]] = d.setdefault(s[i], []) +[i]

            print(d)
    return d
    
cria_dic(str)