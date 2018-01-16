fib = [1]
nextfib = 2
while nextfib <= 4e6:
    fib.append(nextfib)
    nextfib += fib[-2]

ans = sum(x for x in fib if x % 2 == 0)

print(ans)