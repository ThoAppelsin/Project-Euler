from functools import reduce

factordicts = {1 : {}}

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

def divcount(fdict):
    return product(count + 1 for f, count in fdict.items())

wanted = 500

triindex = 1
while True:
    tridict = factordict(triindex + 1).copy()
    for factor, count in factordict(triindex).items():
        if factor in tridict:
            tridict[factor] += count
        else:
            tridict[factor] = count
    tridict[2] -= 1

    if divcount(tridict) > wanted:
        ans = triindex * (triindex + 1) // 2
        break
    triindex += 1

print(ans)