def acronimo(cad):
    cad = cad.upper()
    acron = cad[0]
    for i in range(1, len(cad)-1):
        if(cad[i] == ' '):
            acron += cad[i+1]
    return acron

def acronim(cad):
    acron = ''
    cadpart = cad.strip().split()
    for pal in cadpart:
        acron += pal[0].upper()
    return(acron)