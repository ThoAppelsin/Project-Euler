wanted = 5

suchnums = []
digs = 1
while True:
    start = 10 ** (digs - 1)
    end = 9 ** wanted * digs
    if end < start:
        break

    for i in range(start, min(end + 1, 10 ** digs)):
        if i == sum(int(x) ** wanted for x in str(i)):
            suchnums.append(i)

    digs += 1

ans = sum(suchnums) - 1

print(ans)