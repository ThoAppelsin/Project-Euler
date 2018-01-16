def unitfractionreccyclelen(n):
    divident = 1
    dividents = []

    while divident not in dividents:
        dividents.append(divident)
        divident *= 10
        divident %= n

    if divident == 0:
        return 0

    return len(dividents) - dividents.index(divident)

wanted = 1000

ans = max((unitfractionreccyclelen(x), x) for x in range(2, wanted))[1]

print(ans)