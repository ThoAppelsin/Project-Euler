alim = 100
blim = 100

ans = len({a ** b for a in range(2, alim + 1) for b in range(2, blim + 1)})

print(ans)