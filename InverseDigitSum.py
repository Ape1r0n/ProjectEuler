def digit_sum(n: int) -> int:
    sum = 0
    while n > 0:
        sum += n % 10
        n //= 10
    return sum

def s(n: int) -> int:
    i = 0
    while digit_sum(i) != n: 
        i += 1
    return i

def S(k: int) -> int:
    sum = 0
    for n in range(1, k+1):
        sum += s(n)
    return sum


f = [0] * 91
f[1] = 1

for i in range(2, 91):
    f[i] = f[i-1] + f[i-2]
    
ans = 0
for i in range(2, 91):
    ans += S_i(f[i]) % 1000000007
    
print(ans)
