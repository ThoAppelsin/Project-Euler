coins = (1, 2, 5, 10, 20, 50, 100, 200)

def waystomake(amount, atmost = len(coins)):
    if amount < 0:
        return 0

    if amount == 0 or atmost == 1:
        return 1

    return sum(waystomake(amount - coins[i], i + 1) for i in range(atmost))

ans = waystomake(200)

print(ans)