ans = max(x for x in (a * b for a in range(100, 1000) for b in range(100, 1000)) if str(x) == str(x)[::-1])

print(ans)