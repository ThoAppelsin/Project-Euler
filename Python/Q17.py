numberdict = {
    1: 'one',
    2: 'two',
    3: 'three',
    4: 'four',
    5: 'five',
    6: 'six',
    7: 'seven',
    8: 'eight',
    9: 'nine',
    10: 'ten',
    11: 'eleven',
    12: 'twelve',
    13: 'thirteen',
    14: 'fourteen',
    15: 'fifteen',
    16: 'sixteen',
    17: 'seventeen',
    18: 'eighteen',
    19: 'nineteen',
    20: 'twenty',
    30: 'thirty',
    40: 'forty',
    50: 'fifty',
    60: 'sixty',
    70: 'seventy',
    80: 'eighty',
    90: 'ninety'
}

for i in range(2, 10):
    for j in range(1, 10):
        numberdict[i * 10 + j] = numberdict[i * 10] + '-' + numberdict[j]

# complete up to 100

for i in range(1, 10):
    numberdict[i * 100] = numberdict[i] + ' hundred'
    for j in range(1, 100):
        numberdict[i * 100 + j] = numberdict[i * 100] + ' and ' + numberdict[j]

# complete up to 999

numberdict[1000] = 'one thousand'

ans = sum(len(numberdict[x].replace(' ', '').replace('-', '')) for x in numberdict)

print(ans)