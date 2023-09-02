def aux(n):
    l = list(range(n))
    for i in range(1, n):
        p = l[i]
        for j in range(2 * i, n, i):
            l[j] -= p
    return l

x = 0
ans = 0
l = aux(1000001)
for i in range(2, 1000001):
    if i / l[i] > x:
        x = i / l[i]
        ans = i

print(ans)
