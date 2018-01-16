num = 600851475143
factors = []

factor = 2
while factor <= num:
    if num % factor == 0:
        factors.append(factor)
        num /= factor
    else:
        factor += 1

ans = max(factors)

print(ans)