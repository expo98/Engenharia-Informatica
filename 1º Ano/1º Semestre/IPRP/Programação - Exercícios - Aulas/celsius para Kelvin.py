print('Introduza uma temperatura em graus celsius para converter em Kelvin:')
celsius = float(input())
kelvin = (9/5 * celsius) + 32
while celsius < -273.15:
    print('Temperatura inválida, por favor introduza uma temperatura acima de -273.15ºC:')
    celsius = float(input())
    kelvin = (9/5 * celsius) + 32
print(celsius, 'ºC convertido em Kelvin é ', kelvin, 'K')

