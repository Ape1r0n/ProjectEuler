import math


def primes(n):
    return [prime for (prime, predicate) in enumerate(sieve_of_erathpstenes(n)) if predicate]
    
def is_palindrome(x):
    return x == x[::-1]

def is_quadratic(x):
    return math.isqrt(x) ** 2 == x

def sieve_of_erathpstenes(n):
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False
    for i in range(int(math.sqrt(n)) + 1):
        if sieve[i]:
            for j in range(2 * i, len(sieve), i):
                sieve[j] = False
    return sieve

is_prime = sieve_of_erathpstenes(5*10**7)
primes_list = [i for (i, isprime) in enumerate(is_prime) if isprime]
reversible_prime_squares = []

ans = 0
for i in primes_list[4:]:
    sqrt = str(i*i)
    if not is_palindrome(sqrt):
        reverse = int(sqrt[::-1])
        if is_quadratic(reverse):
            if is_prime[int(math.sqrt(reverse))]:
                reversible_prime_squares.append(int(sqrt))
                reversible_prime_squares.append(reverse)

print(sum(sorted(set(reversible_prime_squares))[:50]))
