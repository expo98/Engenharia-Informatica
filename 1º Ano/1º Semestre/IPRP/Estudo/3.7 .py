import math

def desordem(p1,p2):
    p1_proporcao = p1 / (p1+p2)
    p2_proporcao = p2 / (p1+p2)

    if p1 == 0 or p2 == 0:
        desordem = 0

    else:
        p1_desordem = - (p1_proporcao* math.log2(p1_proporcao))
        p2_desordem = - (p2_proporcao* math.log2(p2_proporcao))
        
        desordem = p1_desordem + p2_desordem
        
    return desordem


print(desordem(5768798,3000))
        
