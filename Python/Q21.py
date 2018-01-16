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

wanted = int(1e4)
divsums = [sumofproperdivisors(x) for x in range(wanted)]
divsums[0] = 0
amicables = [num for num, divsum in enumerate(divsums) if divsum < len(divsums) and divsums[divsum] == num and divsum != num]

ans = sum(amicables)

print(ans)