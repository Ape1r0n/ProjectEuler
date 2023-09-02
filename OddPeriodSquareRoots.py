import math


def continued_fraction_period(n):
    m, d, a = 0, 1, int(math.sqrt(n))
    a_0 = a
    period = 0
    
    while a != 2 * a_0:
        m = d * a - m
        d = (n - m * m) // d
        a = (a_0 + m) // d
        period += 1
    
    return period


count = 0
for i in range(2, 10001):
    if math.isqrt(i) ** 2 != i:
        p = continued_fraction_period(i)
        if p & 1 == 1:
            count += 1

print(count)
