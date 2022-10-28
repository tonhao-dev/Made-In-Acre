# pegando a quantidade de casos de teste
casos = int(input())

for teste in range(casos):
    # colocando os caracteres em minúsculo
    palavra = input().lower() 
    # criando o dicionário caracteres; vai guardar uma tupla caractere-repetições
    caracteres = {}
    
    # andando por cada caractere, inserindo no dicionario e contando
    for c in palavra:
        if c.isalpha() and c not in caracteres:
            caracteres[c] = palavra.count(c)

    # ordenando o dicionário
    caracteres_ordenados = sorted(caracteres.items(), key=lambda x: (-x[1],x[0]))
    
    # pegando a primeira tupla do vetor: posição 0 da estrutura de tuplas, posição 1 na tupla
    maior = caracteres_ordenados[0][1]
    
    resultado = ''
    
    # passando pelo vetor para comparar os que apareceram mais vezes
    for c in caracteres_ordenados:
        if c[1] == maior:
            resultado += c[0]
        else:
            break
    
    print(resultado)