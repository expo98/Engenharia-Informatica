def prefixos(cadeia):
    i=1
    for i in range(len(cadeia)+1):
        print(cadeia[:i])
        i +=1

prefixos("Monty Python e etc etc etc e etc e etc e etc etc etc etc et cetctetetcettc")