# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
path = r"/Users/miguempereira/Engenharia Informática/2º Ano/1º Semestre/Teoria da Informação/TP1"
excel_file = "/CarDataset.xlsx"

import math
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import huffmancodec as huffc

#Exercicio 1

    
 # Exercicio 2 
def create_relational_graphics(nome_variaveis,data):     
    fig,array_figuras = plt.subplots(nrows=3, ncols=2, figsize=(12, 8))  #fig representa a figura, array_figuras é uma matriz 2D
    
    for i, variable in enumerate(nome_variaveis):
        if variable != 'MPG':
            row = i // 2
            col = i % 2
            array_figuras[row, col].scatter(data[variable], data['MPG'], marker='o', alpha=0.5,c='m')
            array_figuras[row, col].set_title(f'{variable} vs MPG')
            array_figuras[row, col].set_xlabel(variable)
            array_figuras[row, col].set_ylabel('MPG')

    plt.subplots_adjust(wspace=0.6, hspace=0.6)

    plt.show()


#Exercicio 4

def conta_ocorrencias_lista(lista,alfabeto):
    dicionario={}
    for valor in alfabeto:
        dicionario[valor]=0
    for valor in lista:
        dicionario[valor]+=1
    return dicionario


    
#Exercicio 5

def plot_bar_chart(dic,nome_var):
   
    chaves_dic = [variable for variable, value in dic.items() if value != 0]
    values = [value for variable, value in dic.items() if value != 0]

    num_bars = len(chaves_dic)
    bar_width = 0.8  
    x_positions = np.arange(num_bars)
    plt.figure(figsize=(10, 5))  
    plt.bar(x_positions, values, width=bar_width, color='red')
    plt.xticks(x_positions, chaves_dic)
    plt.xlabel(nome_var)
    plt.ylabel('Count')
    

    plt.show()


def most_common_value(numbers):
    arr = np.array(numbers)
    most_common_value, count = np.unique(arr, return_counts=True)
    most_common_value = most_common_value[np.argmax(count)]
    return most_common_value

#   Exercicio 6


def substitui_simbolos_intervalo(data,var,target):
        valor_final = np.max(data[var])
        valor_ini = np.min(data[var])
        lista_valores=data[var].copy()
        index=0
        for valor in lista_valores:
            
            if (valor <= valor_final and valor >= valor_ini):
                lista_valores[index]=target
            index+=1
        return lista_valores
    


#
def converte_ocur_prob(dic,n):
    lista=list(dic.values())
    index=0
    for valor in lista:
        lista[index]=valor/n
        index+=1
    return lista




#6

def binning1(data, alfabeto, var, consecutivos):
    lista_valores = data[var].copy()
    dic_oc = conta_ocorrencias_lista(lista_valores, alfabeto)
    bin_size = consecutivos
    num_bins = len(lista_valores) // bin_size
    nova_lista=[]
    for i in range(num_bins):
        flag_init = i * bin_size
        flag_end = (i + 1) * bin_size
        
        if flag_end > len(lista_valores):
            flag_end = len(lista_valores)

        new_d = {key: dic_oc[key] for key in lista_valores[flag_init:flag_end]}
        valor_max = max(new_d, key=lambda key: new_d[key])
        
        nova_lista.append(valor_max)

    return nova_lista
#Exercicio 7
#a)    

def lista_prob(var,alfabeto):
    dicio_var=conta_ocorrencias_lista(var, alfabeto)
    lista_prob=converte_ocur_prob(dicio_var, len(var))
    return lista_prob
            

def calcula_entropia(var,alfabeto):
    lista_probabilidades=lista_prob(var, alfabeto)
    
    total_prob = np.sum(lista_probabilidades)
    if total_prob == 0:
       return 0.0
        
    lista_normalizada = lista_probabilidades / total_prob
    lista_normalizada = lista_normalizada[np.nonzero(lista_normalizada)]
    entropia = -sum(lista_normalizada* np.log2(lista_normalizada))  
    
    return entropia

def calcula_entropia_total(probabilidades_arrays):
    probabilidades_flat = np.concatenate(probabilidades_arrays)
    
    total_prob = np.sum(probabilidades_flat)
    if total_prob == 0:
       return 0.0
        
    lista_normalizada = probabilidades_flat / total_prob
    lista_normalizada = lista_normalizada[np.nonzero(lista_normalizada)]
    entropia = -sum(lista_normalizada* np.log2(lista_normalizada)) 
    
    return entropia

#Exercicio 8
def valor_medio_bits_H(data,var,alfabeto):
    dicionario=conta_ocorrencias_lista(data[var], alfabeto)
    lista_probabilidades=converte_ocur_prob(dicionario,len(data[var]))
    codec=huffc.HuffmanCodec.from_data(data[var]) 
    symbols, lenghts=codec.get_code_len()     
    valor_medio_bits_simbolo= sum(lista_probabilidades[symbols[i]]*lenghts[i] for i in range(len(lenghts)))
    variance = sum(lista_probabilidades[symbols[i]] * (lenghts[i] - valor_medio_bits_simbolo) ** 2 for i in range(len(lenghts)))
    return valor_medio_bits_simbolo,variance


#Ex9
def coeficiente_corr(var1,var2,data):
    matriz_correlacao=np.corrcoef(data[var1],data[var2])
    return matriz_correlacao[0][1]


#Ex 10
def calcular_informacao_mutua(X,Y,bins,alfabeto):
    np.histo
    c_XY = np.histogram2d(X,Y,bins)[0]
    c_X = np.histogram(X,bins)[0]
    c_Y = np.histogram(Y,bins)[0]
    
    
    H_X = calcula_entropia(c_X,alfabeto)
    H_Y = calcula_entropia(c_Y,alfabeto)
    H_XY = calcula_entropia(c_XY,alfabeto)
 
    MI = H_X + H_Y - H_XY
    return MI
                
#Ex 11
def expected_MPG(data,x,n):
    MPGpred = -5.5241
    
    if "Acceleration" != n:
        MPGpred += -0.146 * data["Acceleration"][0]
    if "Cylinders" != n:
        MPGpred += -0.4909 * data["Cylinders"][0]
    if "Displacement" != n:
        MPGpred += 0.0026 * data["Displacement"][0]
    if "Horsepower" != n:
        MPGpred += -0.0045 * data["Horsepower"][0]
    if "ModelYear" != n:
        MPGpred += 0.6725 * data["ModelYear"][0]
    if "Weight" != n:
        MPGpred += - 0.0059 * data["Weight"][0]
        
    return MPGpred


def main():
    #Exercicio 1
    
    data = pd.read_excel(path+excel_file)

    matriz_valores = data.values

    nome_variaveis = data.columns.values.tolist()
    
    # Exercicio 3
    alfabeto_uint16 = np.arange(0, 2**16, dtype=np.uint16)
   # Exercicio 4
   
    dicionario_Acceleration=conta_ocorrencias_lista(data["Acceleration"], alfabeto_uint16)
    
   
    #Exercicio 2
    create_relational_graphics(nome_variaveis,data)
        
    plot_bar_chart(dicionario_Acceleration,"Acceleration")

    

    # Exercicio 6 a) b)
    #encontrar o valor mais comum
    most_common_value_Weight=most_common_value(data['Weight'])
    most_common_value_Displacement=most_common_value(data['Displacement'])
    most_common_value_Acceleration=most_common_value(data['Acceleration'])
    
    #Cria dicionario valor:n*ocorrencias já com o valor mais comum substituido no intervalo a definir
    
    #dicio_weight=conta_ocorrencias_lista(substitui_simbolos_intervalo(data,'Weight', valor_ini, valor_final, most_common_value_Weight), alfabeto_uint16) 
    
    #dicio_displacement=conta_ocorrencias_lista(substitui_simbolos_intervalo(data,'Displacement',valor_ini,valor_final,most_common_value_Displacement),alfabeto_uint16)
    
    #dicio_acceleration=conta_ocorrencias_lista(substitui_simbolos_intervalo(data,'Acceleration',valor_ini,valor_final,most_common_value_Acceleration),alfabeto_uint16)
        
    #Cria os gráficos 
   # plot_bar_chart(dicio_weight,'Weight')
   # plot_bar_chart(dicio_displacement,'Displacement')
   # plot_bar_chart(dicionario_Acceleration,"Acceleration")
    
   #Exercicio 6 d)
   
    lista_weight_binned=binning1(data, alfabeto_uint16,"Weight", 40)
    #print(f'Esta é a lista de pesos em bins {lista_weight_binned}')
    
    dic_weight_binned=conta_ocorrencias_lista(lista_weight_binned, alfabeto_uint16)
    plot_bar_chart(dic_weight_binned, "Weight")
   
    
   
    #Exercicio 6 e)
    lista_displacement_binned=binning1(data, alfabeto_uint16, 'Displacement', 5)
    #print(f'Esta é a lista de displacement em bins {lista_displacement_binned}')
    dic_displacement_binned=conta_ocorrencias_lista(lista_displacement_binned, alfabeto_uint16)
    plot_bar_chart(dic_displacement_binned,'Displacement')
    
    lista_horsepower_binned=binning1(data, alfabeto_uint16, 'Horsepower', 5)
    #print(f'Esta é a lista de horsepower em bins {lista_horsepower_binned}')
    dic_horsepower_binned=conta_ocorrencias_lista(lista_horsepower_binned, alfabeto_uint16)
    plot_bar_chart(dic_horsepower_binned,'horsepower')
   
   
   #Exercicio 7
    
   # a)

    #entropia_acc=calcula_entropia(data,'Acceleration', alfabeto_uint16)
    #print("A entropia da aceleração é:", entropia_acc)
    # b)
    
    probabilidades=[]
    for variavel in nome_variaveis:
        probabilidades.append(lista_prob(data[variavel], alfabeto_uint16))
    entropia_total=calcula_entropia_total(probabilidades)
    #print("Entropia total:", entropia_total)
    

    #print(conta_ocorrencias_lista(data['MPG'], alfabeto_uint16))

    #Exercicio 8
    valor_medio_bits_acc,variancia_acc= valor_medio_bits_H(data,'Acceleration', alfabeto_uint16)
    print(f'O valor medio de bits da acceleração com Huffman é {valor_medio_bits_acc} e a variancia é {variancia_acc}\n')



    
   
    #Exercicio 9
    
    corr_mpg_acc=coeficiente_corr('MPG', 'Acceleration', data)
    #print(f'O coeficiente de correlação entre MPG e Acceleration é {corr_mpg_acc}')
    
    #Exercicio 10
    # Calcular a MI entre "MPG" e "Weight" após o agrupamento
   # mi_mpg_weight = calcular_informacao_mutua(data['MPG'], data['Weight'])

    # Calcular a MI entre "MPG" e "Displacement" após o agrupamento
   # mi_mpg_displacement = calcular_informacao_mutua(data['MPG'], data['Displacement'])
    
    # Calcular a MI entre "MPG" e "Horsepower" após o agrupam
  #c  mi_mpg_horsepower = calcular_informacao_mutua(data["MPG"],data["Horsepower"] )
    
    #print(mi_mpg_horsepower)
    
    #exercicio 11 b)c)
    max_nova= calcular_informacao_mutua(data['MPG'], data['MPG'],30,alfabeto_uint16)
    min_nova= max_nova
    max_nova = min_nova
    min_var = nome_variaveis[0]
    max_var = nome_variaveis[0]
    for i in nome_variaveis:
        nova = []
        if i != 'MPG':
            mi_mpg_i = calcular_informacao_mutua(data['MPG'], data[i],30,alfabeto_uint16)
            nova.append(mi_mpg_i) 
            if nova > max_nova:
                max_nova = nova
                max_var = i
            if nova < min_nova:
                min_nova = nova
                min_var = i
                
    #print(min_var)
    #print(max_var)
    
    MPG_exp = expected_MPG(data, 0, 'NONE')
    MPG_exp_min = expected_MPG(data, 0, min_var)
    MPG_exp_max = expected_MPG(data, 0, max_var)
    #print(MPG_exp)
    #print(MPG_exp_min)
    #print(MPG_exp_max)
    
    

    for nome in nome_variaveis:
        entropia = calcula_entropia(data[nome], alfabeto_uint16)
        valor_medio_bits = valor_medio_bits_H(data, nome, alfabeto_uint16)[0]
    
        print(nome)
        print("A entropia normal é:", entropia)
        print("Número médio de bits com Huffman:", valor_medio_bits)
        print('\n\n') 
    
    

if __name__ == "__main__":
    main()






       