def digit_chain_result(n: int) -> int:
    while n != 1 and n != 89:
        x = n
        n = 0
        while x:
            n += (x % 10) * (x % 10)
            x = x // 10
    return n

ans = 0
for i in range(1,10**7):
    print(i)
    if digit_chain_result(i) == 89:
        ans += 1
print(ans)
