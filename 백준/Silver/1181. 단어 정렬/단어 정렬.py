n = int(input())

l = []

def compare(a):
    return (len(a), a)
    

for _ in range(n):
    x = input()
    if x not in l:
        l.append(x)

l.sort(key=compare)

print('\n'.join(l))