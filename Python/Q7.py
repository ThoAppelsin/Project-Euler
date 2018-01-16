from math import ceil

psieve = [0, 0] # zero and one are not primes by definition

def extendsieve(limit):
    previouslimit = len(psieve)
    
    psieve.extend([1] * (limit - previouslimit))
    for n, isprime in enumerate(psieve):
        if isprime:
            for k in range(max(ceil(previouslimit / n), 2) * n, limit, n):
                psieve[k] = 0

wanted = 10001

while sum(psieve) < wanted:
    extendsieve(len(psieve) * 10)

primes = [n for n, isprime in enumerate(psieve) if isprime]
ans = primes[wanted - 1]

print(ans)