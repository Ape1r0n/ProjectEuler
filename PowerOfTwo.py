import math


def logs_are_helpful(n):
    lb, ub = math.log(1.23, 10), math.log(1.24, 10)
    constant = math.log(2,10)
    count, j = 0, 1

    while count != n:
        temp = j * constant
        if lb < temp - math.floor(temp) < ub:
            count += 1
        j += 1
    
    return j - 1


ans = logs_are_helpful(678910)
print(ans)
