def prime_sieve(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    primes = [i for i, prime in enumerate(is_prime) if prime]
    return primes

def pell(d):
    p, k, x1, y, sd = 1, 1, 1, 0, int(d ** 0.5)
 
    while k != 1 or y == 0:
        p = k * (p // k + 1) - p
        p = p - ((p - sd) // k) * k
 
        x = (p * x1 + d * y) // abs(k)
        y = (p * y + x1) // abs(k)
        k = (p * p - d) // k
        x1 = x
    return x
 
result = max(((pell(d), d) for d in prime_sieve(1000)), key = lambda x: x[0])
print("x:", result[0], "D:", result[1], sep=' ')
