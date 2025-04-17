def counting_numbers(fileToRead):
    algarisms = ("1","2","3","4","5","6","7","8","9","0")
    etc=0
    numbers=[]

    file = open(fileToRead, "r")
    data = file.read()
    number_of_characters = len(data)
    for i in range(len(data)):
        for algarism in algarisms:
            file.seek(i)
            print(file.read(1))
            if (file.read(1) == algarism):
                numbers.append(algarism)
    return numbers


print(counting_numbers("cenas.txt"))