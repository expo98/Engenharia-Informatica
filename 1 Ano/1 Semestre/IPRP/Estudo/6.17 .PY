etc ={
    'joao':18,
    'pedro':18,
    'antonio':17,
    'manuel':19
}

# MINHA SOLUÇÃO
"""def inverte_c_v(nomes):
    nomes_invert={}
    for c,v in nomes.items():
        nomes_invert[v]=c

    return nomes_invert"""

#SOLUÇÃO CORRECTA
def inverte_c_v(dicio):
    inv = {}
    for c, v in dicio.items():
        inv[v] = inv.get(v,[]) + [c]
    return inv

print(inverte_c_v(etc))
