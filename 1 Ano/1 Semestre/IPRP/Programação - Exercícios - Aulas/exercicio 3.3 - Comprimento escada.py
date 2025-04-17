import math

alt = float(input("\nIntroduza a altura da parede: "))
anggraus = float(input("\nIntroduza o ângulo (em graus) que quer que a escada fique em relação à parede: "))

angrads = (math.pi / 180) * anggraus

comp = ("{:.2f}".format (alt / (math.sin(angrads))))

print("\nO comprimento da escada para alcançar uma parede com altura de " + str(alt) + " e um ângulo de " + str(anggraus) + " graus é de comprimento igual a " + str(comp))