from math import ceil

psieve = [0, 0] # zero and one are not primes by definition

def extendsieve(limit):
    previouslimit = len(psieve)
    
    psieve.extend([1] * (limit - previouslimit))
    for n, isprime in enumerate(psieve):
        if isprime:
            for k in range(max(ceil(previouslimit / n), 2) * n, limit, n):
                psieve[k] = 0

wanted = int(2e6)

extendsieve(wanted)

ans = sum(n for n, isprime in enumerate(psieve) if isprime)

print(ans)