from collections import defaultdict

l = defaultdict(list)
for i in range(1000, 10000):
    cube = i ** 3
    key = ''.join(sorted(str(cube)))
    l[key].append(cube)

for i in l.values():
    if len(i) == 5:
        print(sorted(i)[0])
        exit()
