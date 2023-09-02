def is_concealed(n):
    s = str(n)
    base = "1_2_3_4_5_6_7_8_9_0"

    if len(s) != len(base):
        return False

    return all(s[i] == base[i] for i in range(0, len(s), 2))

print(next((n for n in range(1000000000, 2000000000, 10) if (n % 100 == 30 or n % 100 == 70) and is_concealed(n*n))))
