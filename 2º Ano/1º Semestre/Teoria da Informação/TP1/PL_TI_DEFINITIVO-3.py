# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
path = r"/Users/miguempereira/Engenharia Informática/2º Ano/1º Semestre/Teoria da Informação/TP1/"
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

def lista_prob(data,var,alfabeto):
    dicio_var=conta_ocorrencias_lista(data[var], alfabeto)
    lista_prob=converte_ocur_prob(dicio_var, len(data[var]))
    return lista_prob
            

def calcula_entropia(data,var,alfabeto):
    lista_probabilidades=lista_prob(data, var, alfabeto)
    probabilities=np.array(lista_probabilidades)
    non_zero_indices = np.where(probabilities != 0)[0]
    non_zero_probabilities = probabilities[non_zero_indices]
    entropy = -np.sum(non_zero_probabilities * np.log2(non_zero_probabilities)) 
    return entropy

def calcula_entropia_total(probabilidades_arrays):
    probabilidades=np.array(probabilidades_arrays).flatten()
    non_zero_indices = np.where(probabilidades != 0)
    non_zero_probabilidades = probabilidades[non_zero_indices]
    entropia = -np.sum(non_zero_probabilidades * np.log2(non_zero_probabilidades))
    
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
#MAE = sum()

#Ex9
def coeficiente_corr(var1,var2,data):
    matriz_correlacao=np.corrcoef(data[var1],data[var2])
    return matriz_correlacao[0][1]


#Ex 10
def calcular_informacao_mutua(var1, var2):
        var1_unico, count_var1 = np.unique(var1, return_counts=True)
        var2_unico, count_var2 = np.unique(var2, return_counts=True)
    
        prob_conjunta = np.zeros((len(var1_unico), len(var2_unico)))
        prob_marg_var1 = count_var1 / len(var1)
        prob_marg_var2 = count_var2 / len(var2)
    
        for i, val1 in enumerate(var1_unico):
            for j, val2 in enumerate(var2_unico):
                prob_conjunta[i, j] = np.sum((var1 == val1) & (var2 == val2)) / len(var1)
    
        mi = 0
        for i in range(len(var1_unico)):
            for j in range(len(var2_unico)):
                if prob_conjunta[i, j] > 0:
                    mi += prob_conjunta[i, j] * np.log(prob_conjunta[i, j] / (prob_marg_var1[i] * prob_marg_var2[j]))
                    return mi
#Ex11             
def MAE (MPG, expct):
    expct = np.array(expct)
    MPG = np.array(MPG)
    return np.mean(np.abs(MPG-expct))


def expected_MPG(data,n):
    MPGpred = []    
    for i in range(len(data['MPG'])):
        MPGpred_i = -5.5241
    
        if "Acceleration" != n:
            MPGpred_i += (-0.146 * data["Acceleration"][i])
        if "Cylinders" != n:
            MPGpred_i += (-0.4909 * data["Cylinders"][i])
        if "Displacement" != n:
            MPGpred_i += (0.0026 * data["Displacement"][i])
        if "Horsepower" != n:
            MPGpred_i += (-0.0045 * data["Horsepower"][i])
        if "ModelYear" != n:
            MPGpred_i += (0.6725 * data["ModelYear"][i])
        if "Weight" != n:
            MPGpred_i += (- 0.0059 * data["Weight"][i])
        
        MPGpred.append(MPGpred_i)
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
    for variavel in nome_variaveis:
        entropia_acc=calcula_entropia(data,variavel, alfabeto_uint16)
        #print("A entropia da",variavel,"é:", entropia_acc)
    # b)
    
    probabilidades=[]
    for variavel in nome_variaveis:
        probabilidades.append(lista_prob(data, variavel, alfabeto_uint16))
    entropia_total=calcula_entropia_total(probabilidades)
    #print("Entropia total:", entropia_total)
    



    #Exercicio 8
    valor_medio_bits_acc,variancia_acc= valor_medio_bits_H(data,'Acceleration', alfabeto_uint16)
    #print(f'O valor medio de bits da acceleração com Huffman é {valor_medio_bits_acc} e a variancia é {variancia_acc}\n')



    
   
    #Exercicio 9
    
    corr_mpg_acc=coeficiente_corr('MPG', 'Acceleration', data)
    for nome in nome_variaveis:
        print(f'O coeficiente de correlação entre MPG e {nome} é:', coeficiente_corr('MPG',nome,data))
    
    #Exercicio 10
    # Calcular a MI entre "MPG" e "Weight" após o agrupamento
    mi_mpg_weight = calcular_informacao_mutua(data['MPG'], data['Weight'])

    # Calcular a MI entre "MPG" e "Displacement" após o agrupamento
    mi_mpg_displacement = calcular_informacao_mutua(data['MPG'], data['Displacement'])
    
    # Calcular a MI entre "MPG" e "Horsepower" após o agrupam
    mi_mpg_horsepower = calcular_informacao_mutua(data["MPG"],data["Horsepower"] )
    
    print(f'A informação mutua entre MPG e Weight é {mi_mpg_weight}')
    print(f'A informação mutua entre MPG e Displacemente é {mi_mpg_displacement}')
    print(f'A informação mutua entre MPG e Horsepower é {mi_mpg_horsepower}')
    
    #print(mi_mpg_horsepower)
    
    #exercicio 11 b)c)
    max_nova= calcular_informacao_mutua(data['MPG'], data[nome_variaveis[0]])
    min_nova= max_nova
    max_nova = min_nova
    min_var = nome_variaveis[0]
    max_var = nome_variaveis[0]
    for i in nome_variaveis:
        nova = []
        if i != 'MPG':
            mi_mpg_i = calcular_informacao_mutua(data['MPG'], data[i])
            nova.append(mi_mpg_i) 
            if nova > max_nova:
                max_nova = nova
                max_var = i
            if nova < min_nova:
                min_nova = nova
                min_var = i
                
    #print(min_var)
    #print(max_var)
    
    MPG_exp = expected_MPG(data, 'NONE')
    MPG_exp_min = expected_MPG(data, min_var)
    MPG_exp_max = expected_MPG(data, max_var)
    #print("Erro de MPG de todas as variaveis",MAE(data['MPG'], MPG_exp), "MPG previsto:",np.average(MPG_exp))
    #print("Erro de MPG sem a aceleração",MAE(data['MPG'], MPG_exp_min), "MPG previsto:",np.average(MPG_exp_min))
    #print("Erro de MPG sem a aceleração",MAE(data['MPG'], MPG_exp_max), "MPG previsto:",np.average(MPG_exp_max))
    #print(MPG_exp_min)
    #print(MPG_exp_max)
    

    
    

if __name__ == "__main__":
    main()






       