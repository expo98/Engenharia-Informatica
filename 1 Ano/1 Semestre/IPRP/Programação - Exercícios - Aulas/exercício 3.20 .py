import string 

senha = str(input("Introduza algo para ser encriptado: "))
shift = int(input("\n Introduza a distância para qual serão encriptados:  "))
shift %= 26

alfabeto = string.ascii_lowercase
distanciado = alfabeto[shift:] + alfabeto[:shift]
tabela = str.maketrans(alfabeto, distanciado)

codificado = senha.translate(tabela)

print(codificado)