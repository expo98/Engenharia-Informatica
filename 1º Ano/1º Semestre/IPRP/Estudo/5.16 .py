def numero_perfeito(numero):
    divisores=[]
    
    for i in range(1,numero):
        if numero%i == 0:
            divisores.append(i)

    soma_divisores = 0
    for divisor in divisores:
        soma_divisores += divisor

    if soma_divisores == numero:
        return numero, "é um número perfeito"
    else:
        return numero, 'não é um número perfeito'

        
print(numero_perfeito(40))