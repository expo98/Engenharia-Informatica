def cria_sw(listas,n):
    sliding_window=[]

    for i in range(len(listas)-(n-1)):
        window=[]
        for k in range(len(listas)-(n-1)):
            line=[]
            for l in range(n):
                line.append(listas[i][k+l])
            line.append(listas[len(listas)][k+l])
            window.append(line)
    
        sliding_window.append(window)
        
    return sliding_window

lists=[
    [1,2,3,4],
    [4,3,2,1],
    [5,6,7,8],
    [8,7,6,5]]

print(cria_sw(lists,3))

print(len(lists))