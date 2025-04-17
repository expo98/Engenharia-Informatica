list = [1,2,3,4,5,6,7,8,9]

for i in range(1,len(list)):
    list[i] += list[i-1]
print (list)