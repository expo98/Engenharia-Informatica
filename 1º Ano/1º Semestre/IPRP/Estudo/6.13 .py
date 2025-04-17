dias_semana={
    1:'Domingo',
    2:'Segunda-Feira',
    3:'Terça-Feira',
    4:'Quarta-feira',
    5:'Quinta-feira',
    6:'Sexta-Feira',
    7:'Sábado'
    }

meses_ano={
    1:'Janeior',
    2:'Fevereiro',
    3:'Março',
    4:'Abril',
    5:'Maio',
    6:'Junho',
    7:'Julho',
    8:'Agosto',
    9:'Setembro',
    10:'Outubro',
    11:'Novembro',
    12:'Dezembro'
}
# MINHA TENTATIVA
"""def data_funcao(data):
    barra = 0
    for i in range(len(data)):
        if (data[i] == "/") & (barra == 0):
            dia_semana = dias_semana[int(data[:i])]
            barra +=1
            posicao_barra=i

        if (data[i] == "/") & (barra == 1):
            dia_mes = data[posicao_barra:i-1]
            barra+=1
            posicao_barra_2=i

        if (data[i] == "/") & (barra == 2):
            mes = meses_ano[int(6)]
            ano = data[i+1:]
            print(data[posicao_barra_2+1:i-2])

    data_texto = dia_semana, ",", dia_mes, "de", mes, "de", ano
    return data_texto"""

# SOLUÇÃO CORRECTA
def data_funcao(dias_semana,meses_ano,data):
    nova_data=data.split('/')
    print("{0}, {1} de {2} de {3}".format(dias_semana[int(nova_data[0])],nova_data[1],meses_ano[int(nova_data[2])],nova_data[3]))
    

print(data_funcao("4/5/6/2006"))
        
#print(dias_semana[4])




