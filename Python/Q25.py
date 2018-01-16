# By definition:
# fibs[0] = 0
# fibs[1] = 1
fibs = [0, 1]

def fib(n):
    if n >= len(fibs):
        fibs.append(fib(n - 1) + fib(n - 2))

    return fibs[n]

wanted = 1000
ans = 0

while len(str(fib(ans))) < wanted:
    ans += 1

print(ans)