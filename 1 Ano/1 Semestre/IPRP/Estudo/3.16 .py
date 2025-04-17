def sufixos(cadeia):
    i= len(cadeia)-1
    for iterable in range(len(cadeia)):
        print(cadeia[i:len(cadeia)])
        i = i-1

sufixos("Monty Python")