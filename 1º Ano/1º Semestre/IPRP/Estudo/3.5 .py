def duplicar_dinheiro(valor_inicial, taxa_juro):
    anos = 0
    render_dinheiro= 0
    while render_dinheiro < 2*valor_inicial:
        render_dinheiro = valor_inicial * ( (1 + taxa_juro) ** anos)
        if render_dinheiro > 2*valor_inicial:
            return anos
        anos += 1

    
    
print(duplicar_dinheiro(10,0.03))
