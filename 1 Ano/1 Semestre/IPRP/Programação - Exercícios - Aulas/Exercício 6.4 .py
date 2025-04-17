def conta_menores(number,list):
    count=0
    for i in range(0,len(list)):
        if number > list[i]:
            count += 1
    print (count)

def conta_maiores(number,list):
    count=0
    for i in range(0,len(list)):
        if number < list[i]:
            count += 1
    print (count)

conta_menores(5,[2,8,6,5,3,2])
conta_maiores(5,[2,8,6,5,3,2])