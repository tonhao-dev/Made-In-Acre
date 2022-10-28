mascara = [
    [+1, +2],
    [+2, +1],
    [+2, -1],
    [+1, -2],
    [-1, -2],
    [-2, -1],
    [-2, +1],
    [-1, +2]
]

origem_raw, destino_raw = str(input()).split(' ')

origem = [ord(origem_raw[0]) - ord('a') + 1, int(origem_raw[1])]
destino = [ord(destino_raw[0]) - ord('a') + 1, int(destino_raw[1])]

for mascara_posicao in mascara:
  if origem[0] + mascara_posicao[0] == destino[0] and origem[1] + mascara_posicao[1] == destino[1]:
    print('VALIDO')
    exit(0)

print('INVALIDO')
