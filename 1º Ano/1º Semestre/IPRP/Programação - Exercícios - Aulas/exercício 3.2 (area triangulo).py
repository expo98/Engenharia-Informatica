import math
print("\nVamos determinar a área de um triângulo!")
a = float(input("\nIntroduza o comprimento de um primeiro lado do triângulo: "))
b = float(input("\nIntroduza o comprimento de um segundo lado do triângulo: "))
c = float(input("\nIntroduza o comprimento de um terceiro lado do triãngulo: "))

s = (a + b + c) / 2

areatriangulo = math.sqrt( s * (s-a) * (s-b) * (s-c))

print("\nSegundo os comprimentos dos lados que introduziu, o seu triângulo tem área de " + str(areatriangulo))

