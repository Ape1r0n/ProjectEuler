from itertools import islice


def continued_fraction_terms():
    yield 2
    k = 1
    while True:
        yield 1
        yield 2 * k
        yield 1
        k += 1

def rationalize(frac):
    if len(frac) == 0:
        return 1, 0
    elif len(frac) == 1:
        return frac[0], 1
    else:
        remainder = frac[1:]
        num, denom = rationalize(remainder)
        return frac[0] * num + denom, num

numerator = rationalize(list(islice(continued_fraction_terms(), 100)))[0]
ans = sum(int(digit) for digit in str(numerator))
print(ans)
