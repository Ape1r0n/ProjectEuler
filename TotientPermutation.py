def aux(n):
    l = list(range(n))
    for i in range(1, n):
        p = l[i]
        for j in range(2 * i, n, i):
            l[j] -= p
    return l

l = aux(10000001)
l = ((a, b) for a, b in enumerate(l) if sorted(str(a)) == sorted(str(b)) and a > 1)
ans = min(l, key = lambda el: el[0] / el[1])[0]

print(ans)
