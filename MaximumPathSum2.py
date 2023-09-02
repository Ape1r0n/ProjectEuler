table = [list(map(int, i.split())) for i in open('0067_triangle.txt').readlines()]

for i in range(len(table)-1, 0, -1):
    for j in range(0, i):
        table[i-1][j] += max(table[i][j], table[i][j+1])

print(table[0][0])
