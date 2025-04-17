def polinomio(x):
    funcao = (x**3)-x-1
    return funcao


def raiz_polinomio(x_k,x_p):
    
    y_k = polinomio(x_k)
    y_p = polinomio(x_p)

    x_ponto_medio_k_p = (x_k + x_p)/2

    if polinomio(x_ponto_medio_k_p) == 0:
        return x_ponto_medio_k_p

    else:
        x_ponto_medio_k_o = x_k /2
        x_ponto_medio_k_p = x_p /2
        if polinomio(x_ponto_medio_k_o) == 0:
            return x_ponto_medio_k_o
        elif polinomio(x_ponto_medio_k_p) ==0:
            return x_ponto_medio_k_p
        else:
            return -69
        

print(raiz_polinomio(-2,2))
