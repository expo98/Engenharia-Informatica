list = [[0,1,0],[1,1,1],[0,1,0]]

for line in list:
    for i in range(len(line)):
        if line[i]==0:
            line[i]=1
        else:
            line[i]=0

print(list)