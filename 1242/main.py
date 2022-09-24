def tem_ligacao(base1, base2):
    return base1 + base2 in ['BS', 'SB', 'FC', 'CF']


def alguma_base_foi_usada(base_1_foi_usada, base_2_foi_fsada):
    return base_1_foi_usada or base_2_foi_fsada


while True:
    try:
        fita = list(input())
        base_usada = [False] * len(fita)

        if len(fita) == 1:
            print(0)

        ponteiro_a = 0
        ponteiro_b = 1
        ligacoes = 0

        while ponteiro_b < len(fita):
            while ponteiro_a >= 0 and ponteiro_b < len(fita) and tem_ligacao(fita[ponteiro_a], fita[ponteiro_b]) and not alguma_base_foi_usada(base_usada[ponteiro_a], base_usada[ponteiro_b]):
                ligacoes += 1

                print(f'fita[{ponteiro_a}] = {fita[ponteiro_a]}, fita[{ponteiro_b}] = {fita[ponteiro_b]}')

                base_usada[ponteiro_a] = True
                base_usada[ponteiro_b] = True

                ponteiro_a -= 1
                ponteiro_b += 1

            ponteiro_b += 1
            ponteiro_a = ponteiro_b - 1

        # print(ligacoes)

    except EOFError:
        break
