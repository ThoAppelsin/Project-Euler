factordicts = {0: {}, 1: {}}

def factordict(num):
    if num not in factordicts:
        def factordict2(factor):
            if factor ** 2 > num:
                return {num : 1}

            if num % factor == 0:
                subdict = factordict(num // factor).copy()
                if factor in subdict:
                    subdict[factor] += 1
                else:
                    subdict[factor] = 1
                return subdict
            else:
                return factordict2(factor + 1)

        factordicts[num] = factordict2(2)
    
    return factordicts[num]

def product(nums):
    pr = 1
    for x in nums:
        pr *= x
    return pr

def divisors(num):
    fdict = factordict(num)
    pfactors = sorted(fdict)

    def divisors2(divisor=1, pfx=0, pfc=0):
        if pfx >= len(pfactors):
            yield divisor
        else:
            pf = pfactors[pfx]
            if pfc < fdict[pf]:
                yield from divisors2(divisor * pf, pfx, pfc + 1)
            
            yield from divisors2(divisor, pfx + 1)
    
    return divisors2()

def sumofproperdivisors(num):
    return sum(divisors(num)) - num

from math import sqrt, ceil

def isabundant(num):
    root = sqrt(num)
    ceilroot = ceil(root)

    divsum = 1

    if ceilroot == root:
        divsum += ceilroot

    for divisor in range(2, ceilroot):
        if num % divisor == 0:
            divsum += divisor + num // divisor
            if divsum > num:
                return True

    return False

limit = 28123
abundants = [x for x in range(limit) if isabundant(x)]

apsieve = [1] * (limit + 1)
for i, a1 in enumerate(abundants):
    for a2 in abundants[i:]:
        if a1 + a2 > limit:
            break
        
        apsieve[a1 + a2] = 0

ans = sum(ap for ap, isap in enumerate(apsieve) if isap)

# ans = 0

# abundants = []
# apsieve = [0] * (limit + 1)
# for i in range(limit + 1):
#     if isabundant(i):
#         abundants.append(i)

#         for abun in abundants:
#             if abun + i > limit:
#                 break

#             apsieve[abun + i] = 1
    
#     if apsieve[i] == 0:
#         ans += i


print(ans)
