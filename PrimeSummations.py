def prime_range(start, end):
    primes = []
    for num in range(start, end + 1):
        if num > 1:
            is_prime = True
            for i in range(2, int(num**0.5) + 1):
                if num % i == 0:
                    is_prime = False
                    break
            if is_prime:
                primes.append(num)
    return primes

def prime_summations(n):
    numbers = prime_range(1, n)
    cache = [1] + [0] * n

    for number in numbers:
        for i in range(number, n + 1):
            cache[i] += cache[i - number]

    for i, x in enumerate(cache):
        if x > 5000:
            return i

ans = prime_summations(100)
print(ans)
