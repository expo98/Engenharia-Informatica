import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
    
#exercicio 2
def subplots(nomes_variaveis):
    fig, axes = plt.subplots(nrows=3, ncols=2, figsize=(12, 8))  
    for i, variable in enumerate(nome_variaveis):
        if variable != 'MPG':
            row = i // 2
            col = i % 2
            axes[row, col].scatter(data[variable], data['MPG'],c = 'm', marker='o', alpha=0.5)
            axes[row, col].set_title(f'MPG vs {variable}')
            axes[row, col].set_xlabel(variable)
            axes[row, col].set_ylabel('MPG')

    # Ajuste o layout
    plt.tight_layout()
    plt.plot
    plt.subplots_adjust(wspace=0.2, hspace=0.4)
    # Exiba a figura
    plt.show()       


#exercicio 4
def conta_ocorrencias(var,alfabeto):
    dicionario={}
    for valor in alfa:
        dicionario[valor]=0
    lista_valores=data[var].tolist()
    for valor in lista_valores:
        dicionario[valor]+=1
    return dicionario



#exercicio 5
def plot_bar_chart(dic,nome_var):
    # Extrair as chaves (nomes das variáveis) e os valores dos resultados
    chave_dic = [variable for variable, value in dic.items() if value != 0]
    values = [value for variable, value in dic.items() if value != 0]

    num_bars = len(chave_dic)
    bar_width = 0.8  # Adjust the width as needed
    x_positions = np.arange(num_bars)
    plt.figure(figsize=(10, 5))
    plt.bar(x_positions, values, width=bar_width, color='red')
    plt.xticks(x_positions, chave_dic)
    
    plt.xlabel(nome_var)
    plt.ylabel('Count')
    plt.show()
      

#exercicio 6
#array = [1,2,3,2,1]
#for x in range (len(array)):
#    print(np.where(array[x]==1, 10000, array[x]))     
#int = np.range(0,5)
def sim_binning(nome_val):
    #novanova = np.zeros(len(data[nome_val]), dtype = np.uint16)
    nova = data[nome_val]
    conta = np.bincount(nova)
    numero_max_comum = np.argmax(conta)
    for i in range(len(nova)):
         print(np.where(nova[i] == 19, numero_max_comum, nova[i]))
    

if __name__ == '__main__':
    path = r"C:\Users\gfr04\Desktop\LEI\2 ano\TI\TP1"
    excel_file = "\CarDataset.xlsx"
    
    data = pd.read_excel(path+excel_file)
    matriz_valores = data.values
    
    nome_variaveis = data.columns.values.tolist()
    #subplots(nome_variaveis)
    
    alfa = np.arange(0,65535 + 1,dtype = np.uint16)
    
    dicionario_MPG=conta_ocorrencias('MPG', alfa)
    
    dicionario_Acceleration =conta_ocorrencias('Acceleration', alfa)
    
    #plot_bar_chart(dicionario_Acceleration, "Acceleration") 
    
    sim_binning("Acceleration")
   