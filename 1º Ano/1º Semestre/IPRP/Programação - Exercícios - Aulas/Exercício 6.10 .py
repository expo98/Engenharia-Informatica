
#Primeiro exercício
autor = {
    "php":"Ramus Lerdorf", 
    "perl":"Larry Wall", 
    "tcl":"John Ousterhout", 
    "awk":"Brian Kernighan", 
    "java":"James Gosling",
    "parrot":"Simon Cozens",
    "python":"GuidovanRossum",
    "xpto":"zxcv"
}

autor["c++"]="Bjarne Stroustrup"
print(autor)

#Segundo Exercício
autor["python"] = "Guido van Rossum"
print(autor)

#Terceiro Exercício
del autor["xpto"]
print(autor)

#Quarto Exercício
print("O dicionário 'autor' tem", len(autor), "entradas")

#Quinto Exercício
if "c++" in autor:
    print("Há a entrada 'c++' no dicionário 'autor'")
else:
    print("Não existe entrada 'c++' no dicionário 'autor'")