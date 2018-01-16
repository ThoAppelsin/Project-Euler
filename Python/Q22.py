filename = 'p022_names.txt'
file = open(filename)

# the file is known to have just a single line
fcontent = file.readline()

def letterord(letter):
    return ord(letter) - ord('A') + 1

def nameval(name):
    return sum(letterord(l) for l in name)

names = sorted(x[1:-1] for x in fcontent.split(','))
ans = sum((x + 1) * nameval(name) for x, name in enumerate(names))

print(ans)