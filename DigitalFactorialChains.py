ans = 0
factorials = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
d = {}
for i in range(1, 1000000):
    l = []
    while i not in l and i not in d:
        l.append(i)
        i = sum([factorials[int(j)] for j in str(i)])
    for k, v in enumerate(l):
        d[v] = len(l) - k + d.get(i, 0)
        if d[v] == 60:
            ans += 1
print(ans)
