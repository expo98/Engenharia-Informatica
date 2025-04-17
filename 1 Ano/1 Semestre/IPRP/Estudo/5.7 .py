palavra1 = "empatia"
palavra2 = "aurelio"

difere = 0

for i in range(len(palavra1)):
        if palavra1[i] != palavra2[i]:
            difere +=1
if difere/7 < 0.9:
    print("Não são amigas", difere/7)
else:
    print("São amigas", difere/7)

