fruta = ["maca", "pera", "laranja", "diospiro"]
quantidade = [10, 14, 7, 4]

fruta_quantidade = dict()

for i in range(0,len(fruta)):
    fruta_quantidade[fruta[i]] = quantidade[i] 

print(fruta_quantidade)
#Ou assim

def stock_fruta (nome_frutas, quantidade):
    stock={}
    for i in range(len(nome_frutas)):
        chave=nome_frutas[i]
        valor=quantidade[i]
        stock[chave]=valor
    return stock
