n = int(input())
words = []
for _ in range(n):
    words.append(input())

words.sort()

cnt = 0
for i in range(n-1):
    c = words[i]
    ne = words[i+1]
    if c in ne and ne.index(c) == 0:
        cnt += 1

print(n - cnt)