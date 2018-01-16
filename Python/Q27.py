from math import ceil

psieve = [0, 0] # zero and one are not primes by definition

def extendsieve(limit):
    previouslimit = len(psieve)

    psieve.extend([1] * (limit - previouslimit))
    for n, isprime in enumerate(psieve):
        if isprime:
            for k in range(max(ceil(previouslimit / n), 2) * n, limit, n):
                psieve[k] = 0

def isprime(num):
    if num < 0:
        return False

    while num >= len(psieve):
        extendsieve(len(psieve) * 2)

    return psieve[num]

def quadraticf(a, b):
    return lambda n: n * n + a * n + b

lima = 1000
limb = 1000

extendsieve(limb + 1)
blist = [x for x, isprime in enumerate(psieve) if isprime]

anstuple = (0, 0, 0)

for a in range(-lima, lima + 1):
    for b in blist:
        qf = quadraticf(a, b)
        n = 0
        while isprime(qf(n)):
            n += 1

        if n > anstuple[0]:
            anstuple = (n, a, b)

ans = anstuple[1] * anstuple[2]

print(ans)