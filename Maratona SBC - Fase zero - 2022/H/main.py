num_testes = int(input())

entrada = [0] * num_testes
maior_qtd = -1

for i in range(0, num_testes):
    entrada[i] = int(input())

    maior_qtd = max(maior_qtd, entrada[i])

saida = [0] * maior_qtd
saida[0] = 0
i = 0
j = 1

while i < num_testes:
    saida[j] = saida[j - 1] + j * 2 + j - 1

    if saida[j] > entrada[i]:
        print(j - 1)
        i += 1

    j += 1
