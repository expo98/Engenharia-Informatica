#VOLTAR A VER   


list = [[0,1,0],[2,3,4],[0,5,0]]

def roda(img):
    nova_matriz = []
    linhas_img=len(img)
    colunas_img=len(img[0])    
    
    for i in range(colunas_img):
        nova_linha = []
        for j in range(linhas_img):
            nova_linha.append(0)
        nova_matriz.append(nova_linha)
    
    for i in range(colunas_img):
        for j in range(linhas_img):
            nova_matriz[i][j]=img[linhas_img-1-j][i]
    print(nova_matriz)

roda(list)