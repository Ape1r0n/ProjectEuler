from math import log10
numerator, denominator, ans = 3, 2, 0

for i in range(2, 1001):
    numerator, denominator = numerator + 2*denominator, numerator + denominator
    if int(log10(numerator)) > int(log10(denominator)): ans += 1

print(ans)
