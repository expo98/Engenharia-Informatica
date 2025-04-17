def negative(listoflists):
    for list in listoflists:
        for i in range(len(list)):
            if list[i] ==0:
                list[i]=1
            else:
                list[i]=0
    return listoflists

# PORQUE É QUE NÃO DÁ??????
"""def negative(listoflists):
    for list in listoflists:
        for color in list:
            if color ==0:
                color=1
            else:
                color=0
    return listoflists """



print(negative([[1,0,1],[0,1,0],[1,0,1]]))



