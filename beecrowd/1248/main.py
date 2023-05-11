casos = int(input())

for _ in range(casos):
    dieta = input()
    manha = input()
    almoco = input()

    almocoEmanha = almoco + manha

    arrayWord = []
    end = False
    for char in almocoEmanha:
        if char not in dieta:
            print('CHEATER')
            end = True
            break
        if char in arrayWord:
            end = True
            print('CHEATER')
            break
        arrayWord.append(char)
    if end:
        continue

    dieta = sorted(dieta)
    missing_chars = [char for char in dieta if char not in arrayWord]
    print(''.join(missing_chars))
