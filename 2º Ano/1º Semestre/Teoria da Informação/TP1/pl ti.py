# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import math
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import huffmancodec as huffc

path = r"/Users/miguempereira/Engenharia Informática/2º Ano/1º Semestre/Teoria da Informação/TP1"
excel_file = "/CarDataset.xlsx"



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


def agrupa_simbolos(data,var,valor_ini,valor_final,target):
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
    

def lista_prob(data,var,alfabeto):
    dicio_var=conta_ocorrencias_lista(data[var], alfabeto)
    lista_prob=converte_ocur_prob(dicio_var, len(data[var]))
    return lista_prob
            
#Exercicio 7

def calcula_entropia(data,var,alfabeto):
    lista_probabilidades=lista_prob(data, var, alfabeto)
    probabilities=np.array(lista_probabilidades)
    non_zero_indices = np.where(probabilities != 0)[0]
    non_zero_probabilities = probabilities[non_zero_indices]
    entropy = -np.sum(non_zero_probabilities * np.log2(non_zero_probabilities)) 
    return entropy

#Ex9
def coeficiente_corr(var1,var2,data):
    matriz_correlacao=np.corrcoef(data[var1],data[var2])
    return matriz_correlacao[0][1]



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
    
    #dicio_weight=conta_ocorrencias_lista(agrupa_simbolos(data,'Weight', valor_ini, valor_final, most_common_value_Weight), alfabeto_uint16) 
    
    #dicio_displacement=conta_ocorrencias_lista(agrupa_simbolos(data,'Displacement',valor_ini,valor_final,most_common_value_Displacement),alfabeto_uint16)
    
    #dicio_acceleration=conta_ocorrencias_lista(agrupa_simbolos(data,'Acceleration',valor_ini,valor_final,most_common_value_Acceleration),alfabeto_uint16)
        
    #Cria os gráficos 
   # plot_bar_chart(dicio_weight,'Weight')
   # plot_bar_chart(dicio_displacement,'Displacement')
   # plot_bar_chart(dicionario_Acceleration,"Acceleration")
    
   #Exercicio 6 d)
   
    lista_weight_binned=binning1(data, alfabeto_uint16,"Weight", 40)
    print(f'Esta é a lista de pesos em bins {lista_weight_binned}')
    
    dic_weight_binned=conta_ocorrencias_lista(lista_weight_binned, alfabeto_uint16)
    plot_bar_chart(dic_weight_binned, "Weight")
   
    
   
    #Exercicio 6 e)
    lista_displacement_binned=binning1(data, alfabeto_uint16, 'Displacement', 5)
    print(f'Esta é a lista de displacement em bins {lista_displacement_binned}')
    dic_displacement_binned=conta_ocorrencias_lista(lista_displacement_binned, alfabeto_uint16)
    plot_bar_chart(dic_displacement_binned,'Displacement')
    
    lista_horsepower_binned=binning1(data, alfabeto_uint16, 'Horsepower', 5)
    print(f'Esta é a lista de horsepower em bins {lista_horsepower_binned}')
    dic_horsepower_binned=conta_ocorrencias_lista(lista_horsepower_binned, alfabeto_uint16)
    plot_bar_chart(dic_horsepower_binned,'horsepower')
    
    
   
   
   
   
   
   
   
   
   #Exercicio 7
    
   # a)

    entropia_acc=calcula_entropia(data,'Acceleration', alfabeto_uint16)
    
    #7 b))
    
    def joint_entropy(probability_arrays):
    # Filter out zero probabilities for each variable
        non_zero_probabilities = [prob[prob != 0] for prob in probability_arrays]

    # Calculate the joint entropy
        entropy = -np.sum([p * np.log2(p) for p in non_zero_probabilities])

        return entropy

# Example usage:

    
    probabilidades=[]
    for variavel in nome_variaveis:
        probabilidades.append(lista_prob(data, variavel, alfabeto_uint16))
    entropiaconjunta=joint_entropy(probabilidades)
    print("Joint Entropy:", entropiaconjunta)







    


#Exercicio 8
def valor_medio_bits_H(data,var,alfabeto):
    dicionario=conta_ocorrencias_lista(data[var], alfabeto)
    lista_probabilidades=converte_ocur_prob(dicionario,len(data[var]))
    codec=huffc.HuffmanCodec.from_data(data[var]) 
    symbols, lenghts=codec.get_code_len()     
    valor_medio_bits_simbolo= sum(lista_probabilidades[symbols[i]]*lenghts[i] for i in range(len(lenghts)))
    variance = sum(lista_probabilidades[symbols[i]] * (lenghts[i] - valor_medio_bits_simbolo) ** 2 for i in range(len(lenghts)))
    return valor_medio_bits_simbolo,variance


    
    
    #Exercicio 9
    
    corr_mpg_acc=coeficiente_corr('MPG', 'Acceleration', data)
   # print(corr_mpg_acc)
    
    
    

    #Exercicio 11 a)
    def expected_MPG(data,x):
        MPG_pred= -5.5241\
           - (0.146 * data['Acceleration'][x]) \
           - 0.4909 * data['Cylinders'][x] \
           + 0.0026 * data['Displacement'][x] \
           - 0.0045 * data['Horsepower'][x] \
           + (0.6725 * data['ModelYear'][x]) \
           - 0.0059 * data['Weight'][x]
        return MPG_pred
   
    MPG_real=data['MPG'][0]
    MPG_exp=expected_MPG(data, 0)
    print(f'O valor real é {MPG_real} e o valor expectado é {MPG_exp}')
    
    





if __name__ == "__main__":
    main()


# array=[1,2,3,2,1]
# np.where(x==1,1000,x)
#int = nprange(0,5)
#no[int]
#m=npmoj()
#ind=



       