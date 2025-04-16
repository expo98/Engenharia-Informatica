def exercicio7_1():

    file = open("primeir.txt","w")
    file.write("Acabei de criar o meu primeiro ficheiro em Python")
    file.close()

def exercicio7_2(n):

    file = open("primeir.txt","r")
    texto = file.readline(n)
    print(texto)
    file.close()

def exercicio7_3():
    file = open("primeir.txt","a")
    file.write("\n15/10/2024")
    file.close()

def exercicio7_4():
    file = open("primeir.txt","r")
    lista = list()

    for lines in file:
        linha = file.readline()

        for character in linha:
            if character in "0123456789":
                lista.append(int(character))

    print(lista)

    file.close()

def exercicio7_6():
    original_file = input("Nome do ficheiro a copiar: ")
    new_file = input("Nome da copia de {0}: ".format(original_file))

    fOriginal = open(original_file,"r")
    fCopia = open(new_file, "w")

    for lines in fOriginal:
        fCopia.write(lines)

    fOriginal.close()
    fCopia.close()

def exercicio7_11():
    fVendas = open("vendas.txt","r+")

    numVendas = 0
    i = 0
    for line in fVendas:
        if "Venda a Dinheiro No" in line:
            numVendas= line[20:]
    
    nomeEmpresa = input("Introduza o nome da empresa: ")
    numContribuinte = input("Introduza o número de contribuinte da sua empresa: ")
    data = input("Introduza a data da compra: ")
    valor = input("Input introduza o valor da compra: ")
    nomeVendedor = input("Introduza o nome do vendedor: ")

    numVendas = int(numVendas)
    numVendas += 1

    fVendas.write("\n")
    fVendas.write("Venda a Dinheiro No {0}\n".format(numVendas))
    fVendas.write("-----------------\n")
    fVendas.write("Empresa: {0}\n".format(nomeEmpresa))
    fVendas.write("N.C.: {0}\n".format(numContribuinte))
    fVendas.write("Data: {0}\n".format(data))
    fVendas.write("Valor: {0}\n".format(valor))
    fVendas.write("Vendedor:{0} \n".format(nomeVendedor))

    fVendas.close()

def exercicio7_12():

    file = open("numeros.txt","r")

    dicionario = dict()
    linhaNum = list()

    for line in file:
        
        linhaNum = line.split()
        for num in linhaNum:
            if num in dicionario:
                dicionario[num] +=1
            else:
                dicionario[num] = 1

    print(dicionario)

    file.close()

def exercicio7_13():
    
    leitura = open("exercicio713input.txt","r")
    output = open("exercicio713output.txt", "w")

    dados = list()
    for line in leitura:
        dados.append(line.split())

    
    for i in range(len(dados)):
        output.write(dados[i][0][0])
        output.write(dados[i][1][0])

        output.write(" ")

        output.write(dados[i][2])
        
        output.write(" ")

        if int(dados[i][3]) == 102:
            output.write("Professor")
        elif int(dados[i][3]) == 411:
            output.write("Advogado")
        elif int(dados[i][3]) == 203:
            output.write("Estudante")
        output.write(" ")

        if int(dados[i][4]) == 1:
            output.write("Casado")
        elif int(dados[i][4]) == 2:
            output.write("Solteiro")

        output.write("\n")

    leitura.close()
    output.close()

if __name__ == "__main__":
    #exercicio7_1()
    #exercicio7_2(12)
    #exercicio7_3()
    #exercicio7_4()
    #exercicio7_6()
    #exercicio7_11()
    #exercicio7_12()
    exercicio7_13()