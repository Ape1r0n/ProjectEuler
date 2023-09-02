l = list(range(10**6))
for i in range(1, 10**6):
    p = l[i]
    for j in range(2 * i, 10**6, i):
        l[j] -= p
ans = sum(l) - 1
print(ans)
