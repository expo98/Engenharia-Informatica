dados_biometricos={
    14699232:"Masculino,18,1.70,68",
    12345676:"Feminino,28,1.65,55",
    47203990:"Feminino,14,1.65,46"
}


def metabolismo_basal(biometria):
    metabolismo={}
    for chave, valor in biometria.items():
        dados = valor.split(',')
        if dados[0] == "Feminino":
            metabol= 66 + (6.3 * int(dados[3]))   + (12.9 * float(dados[2])) - (6.8 * int(dados[1])) 
        if dados[0] == "Masculino":
            metabol= 66.5 + (4.3 * int(dados[3]))   + (4.7 * float(dados[2])) - (4.7 * int(dados[1])) 
            
        metabolismo[chave] = round(metabol,2)
    return metabolismo



print(metabolismo_basal(dados_biometricos))