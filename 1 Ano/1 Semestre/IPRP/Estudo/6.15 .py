dados_biometricos={
    14699232:["Masculino",18,1.70,68],
    12345676:["Feminino",28,1.65,55],
    47203990:["Feminino",14,1.65,46]
}




def obter_imc(biometria):
    for chave, valor in biometria.items():
        imc = round(valor[3] / valor[2]**2 , 1)
        print(valor)
        print(imc)
        valor = valor.append(imc)
    
    return biometria

obter_imc(dados_biometricos)
print(dados_biometricos)