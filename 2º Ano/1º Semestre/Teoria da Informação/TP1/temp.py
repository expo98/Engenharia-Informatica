# -*- coding: utf-8 -*-
"""/Applications
Spyder Editor

This is a temporary script file.
"""
path = r"/Users/miguempereira/Engenharia Informática/2º Ano/1º Semestre/Teoria da Informação/TP1/"
excel_file = "CarDataset.xlsx"


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


data = pd.read_excel(path+excel_file)

matriz_valores = data.values

nome_variaveis = data.columns.values.tolist()       

fig, axes = plt.subplots(nrows=3, ncols=2, figsize=(12, 8))  
    
for i, variable in enumerate(nome_variaveis):
    if variable != 'MPG':
        row = i // 2
        col = i % 2
        axes[row-1, col-1].scatter(data[variable], data['MPG'],c='m', marker='o', alpha=0.5)
        axes[row-1, col-1].set_title(f'MPG vs {variable}')
        axes[row-1, col-1].set_xlabel(variable)
        axes[row-1, col-1].set_ylabel('MPG')


# Ajustar o layout
plt.tight_layout()
plt.subplots_adjust(wspace=0.2, hspace=0.4)

# Exibir a figura
plt.show()       

#Alfabeto
alfabeto = np.arange(0,65535 + 1, dtype = np.uint16)
print(alfabeto)

