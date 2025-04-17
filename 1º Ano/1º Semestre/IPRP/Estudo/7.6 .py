def copy_file(original_file, new_file):
    original = open(original_file, "r")
    data = original.read()
    
    new= open(new_file, "w")
    new.write(data)
    original.close()
    new.close()

copy_file("omeuficheiro.txt", "copia_omeuficheiro.txt")
