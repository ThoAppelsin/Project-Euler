from operator import itemgetter

collatzlens = {1 : 1}

def collatzlen(n):
    if n not in collatzlens:
        collatzlens[n] = 1 + collatzlen(3 * n + 1 if n % 2 else n // 2)
    
    return collatzlens[n]

ans = max(((num, collatzlen(num)) for num in range(1, int(1e6))), key=itemgetter(1))[0]

print(ans)