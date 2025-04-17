print("Introduz qualquer coisa")

palavra = str(input())

comprimento_palavra = len(palavra)


print( [ palavra [i:i+comprimento_palavra] for i in range(0, comprimento_palavra) ])