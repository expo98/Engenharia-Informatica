def soma_cumulativa(lst):
    lout =[1,2,3]
    for i in range(len(lst)):
        lout += [sum(lst[:i+1])]
    return lout


print("a tua mãe")
print("o teu pai")