stock={
    "maçã" : 10,
    "pêra": 13,
    "abacate": 5,
    "banana": 8
}

sell={
    "maçã" : 1.59,
    "pêra": 1.49,
    "abacate": 3.99,
    "banana": 1.09
}

buying={
    "maçã" : 1.20,
    "pêra": 1.12,
    "abacate": 4.8,
    "banana": .72
}


def get_profit(fruit,quantity):
    selling_price = sell[fruit]
    buying_price=buying[fruit]
    stock[fruit] -= quantity
    profit= (selling_price - buying_price)*quantity
    return round(profit,2)

print(get_profit("maçã",2))
print(stock)

def most_expensive():
    expensive_fruit_price=0
    expensive_fruit_name=""
    for fruit in sell:
        if sell[fruit] > expensive_fruit_price:
            expensive_fruit_price = sell[fruit]
            expensive_fruit_name = fruit
    return expensive_fruit_name

print(most_expensive())

