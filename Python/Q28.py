wanted = 1001

ans = 1 + sum(4 * x ** 2 - 6 * (x - 1) for x in range(3, wanted + 1, 2))

print(ans)