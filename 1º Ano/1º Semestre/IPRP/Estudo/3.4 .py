def batimento_cardiaco_maximo(idade):
    bat_card_max= 163 + (1.16*idade) - (0.018*(idade**2))
    return bat_card_max

print(batimento_cardiaco_maximo(18))