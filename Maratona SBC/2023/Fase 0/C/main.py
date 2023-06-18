[a, b, c] = [int(x) for x in str(input()).split(' ')]
target = str(input())

if target == 'A':
    saida = a * 10
    saida += b * 15
    saida += c * 25

if target == 'B':
    saida = b * 10
    saida += a * ((2/3) * 10)
    saida += c * ((5/3) * 10)

if target == 'C':
    saida = c * 10
    saida += a * 4
    saida += b * 6

print(int(saida / 10))
