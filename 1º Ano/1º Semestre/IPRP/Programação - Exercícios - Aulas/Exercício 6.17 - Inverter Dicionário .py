input = {'joao':10, 'pedro':18,'tiago':13,'luis':18}

def inverte_dic(d):
    inv = {}
    for c,v in d.items():
        inv[v] = inv.setdefault(v,[]) +[c]
        print(inv)

    return inv

    dicio

inverte_dic(input)