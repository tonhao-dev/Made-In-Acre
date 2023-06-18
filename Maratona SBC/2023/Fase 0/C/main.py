# Solução do Daniel Elias
# https://www.instagram.com/daniel.elias_ss/

n,k = list(map(int, input().split()))
n1 = n * 2
while True:
    if n1**2 == k:
        n1 -= 1
        continue
    elif abs(n1**2 - k) % (2*n+ 1) == 0:
        print(n1**2)
        break
    n1 -= 1
