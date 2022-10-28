size_tela = int(input())
num_quebras = 0

while True:
    try:
        linha = list(input())

        if len(linha) <= size_tela:
            num_quebras += 1
            continue

        for i in range(size_tela-1, len(linha), size_tela):
            while i < len(linha) - 1 and linha[i+1] == ' ':
                linha.pop(i + 1)

        num_quebras = (len(linha)/size_tela) + num_quebras
    except EOFError:
        break
        

print(num_quebras)
