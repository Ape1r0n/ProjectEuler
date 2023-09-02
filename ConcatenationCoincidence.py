import math


def aux(theta, limit):
    b_n = theta
    tau = str(math.floor(b_n)) + "."
    
    while len(tau) < limit:
        temp = math.floor(b_n) * (b_n - math.floor(b_n) + 1)
        tau += str(math.floor(temp))
        b_n = temp
    return (tau[:limit])  # includes dot in string representation


ans = "2."
while len(ans) <= 25:
    for i in range(10):
        temp = ans + str(i)
        if temp == aux(float(temp), len(temp)):
            ans += str(i)


print(ans)
