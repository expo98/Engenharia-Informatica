fruit_names=["banana", "maca", "pera", "abacate"]
fruit_weight=[10, 15, 15, 3]

stock= dict()

for i in range(len(fruit_names)):
    stock[fruit_names[i]]=fruit_weight[i]

print(stock)

#OU
sotck={}
for i in range(len(fruit_names)):
    key=fruit_names[i]
    value=fruit_weight[i]
    stock[key]=value

print(stock)