Eulercoins = [1504170715041707]
curr = 1504170715041707
inv = 3451657199285664
i = 2

while True:
    n = (1504170715041707 * i) % 4503599627370517
    if n < curr:
        curr = n
        Eulercoins.append(n)
    if curr == 15806432:
        temp = 1
        maximum = 4503599627370517
        while temp != 15806432:
            n = (temp * inv) % 4503599627370517
            if n < maximum:
                maximum = n
                Eulercoins.append(temp)
            temp += 1
        break
    i += 1

print(sum(Eulercoins))
