autor={
    "php":"Rasmus Lerdorf",
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

autor["python"]="Guido van Rossum"
print(autor)

del autor["xpto"]
print(autor)


print(len(autor))

if "c++" in autor:
    print("Existe entrada c++ em autor")
else:
    print("não existe")
    