count = 0

for n in range(1, 30):
    for num in range(1,10):
        power = num ** n
        if len(str(power)) == n:
            count += 1

print(count)
