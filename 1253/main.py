import string

alfabeto = [x for x in string.ascii_uppercase]

num_testes = int(input())

for i in range(0, num_testes):
    cifra = str(input())
    num_casas = int(input())

    for letra in cifra:
      print(alfabeto[ord(letra) - ord('A') - num_casas], end='')

    print()