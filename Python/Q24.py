from itertools import permutations, islice



def nth(iterable, n, default=None):
    "Returns the nth item or a default value"
    return next(islice(iterable, n, None), default)

digits = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

wanted = int(1e6)

ans = ''.join(str(n) for n in nth(permutations(digits), wanted - 1))

print(ans)