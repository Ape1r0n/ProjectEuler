def aux(n, m):
    if n > m:
        return False
    if n == m:
        return True

    t = 10
    while t < m:
        q, r = m // t, m % t
        if r < n and aux(n - r, q):
            return True
        t *= 10

    return False


ans = 0

for i in range(2, 1000001):
    if aux(i, i * i):
        ans += i * i

print(ans)
