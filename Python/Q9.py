from functools import reduce
import operator

wanted = 1000

suchtriplets = [(wanted - b - c, b, c)
    for c in range(wanted)
    for b in range(min(c, wanted - c))
    if wanted - b - c < b and (wanted - b - c) ** 2 + b ** 2 == c ** 2]
ans = reduce(operator.mul, suchtriplets[0], 1)

print(ans)