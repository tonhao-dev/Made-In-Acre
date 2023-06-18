for i in range(int(input())):
    n = input()
    s = 0
    p = []
    for c in n:
        if c == '<':
            p.append(c)
        elif c == '>':
            if '<' in p:
                p.remove('<')
                s += 1
    print(s)
