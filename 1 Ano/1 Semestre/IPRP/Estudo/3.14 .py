def separar_texto(texto,comprimento):
    cadeia = texto
    a=0
    b=comprimento
    for i in range(int(round(len(cadeia)/comprimento))) :
        print (cadeia[a:b])
        a += comprimento
        b += comprimento



separar_texto("os medicos podem fazer provas",3)
    