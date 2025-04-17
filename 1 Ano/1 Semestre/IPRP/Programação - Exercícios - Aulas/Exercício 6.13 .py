dias_semana={
    1:'Domingo',
    2:'Segunda-Feira',
    3:'Terça-Feira',
    4:'Quarta-Feira',
    5:'Quinta-Feira',
    6:'Sexta-Feira',
    7:'Sábado'
}
meses_ano={
    1:'Janeiro',
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

dias_semana={1:'Domingo',2:'Segunda-Feira',3:'Terça-Feira',4:'Quarta-Feira',5:'Quinta-Feira',6:'Sexta-Feira',7:'Sábado'}
meses_ano={1:'Janeiro',2:'Fevereiro',3:'Março',4:'Abril',5:'Maio',6:'Junho',7:'Julho',8:'Agosto',9:'Setembro',10:'Outubro',11:'Novembro',12:'Dezembro'}
def conversor(dias_semana,meses_ano,data):
    nova_data=data.split('/')
    print("{0}, {1} de {2} de {3}".format(dias_semana[int(nova_data[0])],nova_data[1],meses_ano[int(nova_data[2])],nova_data[3]))
    
conversor(6,2,3)