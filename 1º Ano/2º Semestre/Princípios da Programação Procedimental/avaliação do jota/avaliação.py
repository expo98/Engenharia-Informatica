import math

def volumeIcosaedro(L): 

    volume = ( (5/12)* ( 3 + math.sqrt(5)) * (L**3))

    return volume

print(volumeIcosaedro(1.5))


def volumesMenoresIco (V,S):
    vetor_novo =[]

    for volume in V:
        if volumeIcosaedro(volume) <= S:
            vetor_novo.append(volumeIcosaedro(volume))

    return vetor_novo



print(volumesMenoresIco([1.0,1.5,2.0,2.5,3.0],20.0))