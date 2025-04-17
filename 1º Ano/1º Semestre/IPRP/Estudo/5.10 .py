import random 

def dados_monte_carlo(lancamentos):
    impar = 0
    par = 0 
    for i in range(lancamentos):
        x = random.uniform(-1,1)
        y = random.uniform(-1,1)

        if x >= 0:
            if x <= y:
                impar += 1
            if x > y:
                    par += 1

        if x < 0:
            if y <= 0:
                par += 1

            if y > 0:
                impar += 1
    
    return round(100 * (impar/lancamentos),2)


print(dados_monte_carlo(999999), "%")
    




        