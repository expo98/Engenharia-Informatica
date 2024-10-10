import math

def exercicio1_3():
    distancia_Andromeda_anos_luz = 2900000
    anos_luz = 9.459 * (10**12)
    print("A distancia entre a terra e Andrómeda é ", (distancia_Andromeda_anos_luz / anos_luz))

def exercicio1_4():
    resultado = 365*24*60*60
    print("Um ano normal tem ", resultado, " segundos")

def exercicio1_9(peso,altura):
    imc = peso / (altura**2)
    print("O seu IMC é ", imc)

def exercicio1_10(temperatura_celcius):
    temperatura_fahrenheit = ((9/5) * temperatura_celcius ) + 32
    print("A temperatura Celcius de ", temperatura_celcius, " em Fahrenheit é ", temperatura_fahrenheit)

def exercicio1_17(x_cart,y_cart):
    
    x_cart_2 = x_cart * x_cart
    y_cart_2 = y_cart * y_cart

    hipotenusa = math.sqrt(x_cart_2 + y_cart_2)

    teta= x_cart / hipotenusa
    
    x_pol = hipotenusa * math.cos(teta)
    y_pol =  hipotenusa * math.sin(teta)
    
    print("A x_pol é ", x_pol, " e a y_pol é ", y_pol)

def exercicio1_19(massa_corpo_1, massa_corpo_2, distancia_entre_corpos):
    
    G = 6.67 * math.pow(10,-11)
    
    dividendo = 4 * (math.pi**2)
    divisor = G *(massa_corpo_1 + massa_corpo_2)

    p_2 = (dividendo/divisor) * math.pow(distancia_entre_corpos,3)

    print("Exercício 19 ", p_2)




if __name__ == '__main__':
    exercicio1_3()
    exercicio1_4()
    exercicio1_9(75,1.7)
    exercicio1_10(32)
    exercicio1_17(43,-22)
    