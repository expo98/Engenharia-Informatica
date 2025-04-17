import math

n = float(input("Introduza o número de n objectos: "))
m = float(input("Introduza o número de m objectos: "))

if n == 0 or m == 0:
    desordem_total = 0
else:
    
    p1 = n / (n + m)
    p2 = m / (n + m)

    desordem_p1 = -(p1 * math.log2(p1))
    desordem_p2 = -(p2 * math.log2(p2))

    desordem_total = desordem_p1 + desordem_p2

print("\nA desordem do conjunto é de " + str(desordem_total))