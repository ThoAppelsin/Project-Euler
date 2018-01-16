from functools import reduce

def factordict(num):
    fdict = {}
    factor = 2
    while num >= factor:
        if num % factor == 0:
            if factor in fdict:
                fdict[factor] += 1
            else:
                fdict[factor] = 1
            
            num /= factor
        else:
            factor += 1
    return fdict

ansdict = {}
for num in range(21):
    for factor, count in factordict(num).items():
        if factor in ansdict:
            ansdict[factor] = max(ansdict[factor], count)
        else:
            ansdict[factor] = count

ans = 1
for factor, count in ansdict.items():
    ans *= factor ** count

print(ans)