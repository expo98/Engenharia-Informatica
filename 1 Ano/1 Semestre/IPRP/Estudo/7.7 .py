import turtle
import random

file = open("pairs_of_numbers.txt", "rw+")

file.write(str(random.randint(1,6)))
file.write(str(random.randint(1,6)))
file.write("\n")
file.write(str(random.randint(1,6)))
file.write(str(random.randint(1,6)))

file.readlines()





file.close()

