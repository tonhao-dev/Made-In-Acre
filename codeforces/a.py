d = int(input())  # Lê o valor de d
pairs = []

for k in range(1, int((2 * d)**0.5) + 1):
    if (2 * d - k * (k + 1)) % (2 * k) == 0:
        n = (2 * d - k * (k + 1)) // (2 * k)
        m = n + k
        pairs.append((n, m))

print(len(pairs))
for pair in pairs:
    print(pair[0], pair[1])
