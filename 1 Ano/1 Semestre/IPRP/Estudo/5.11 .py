def factorial(n):
    for i in range (n-1,1,-1):
        n *= i
    return n

print (factorial(5))