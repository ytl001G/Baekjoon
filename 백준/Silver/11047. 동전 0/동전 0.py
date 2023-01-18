n, k = map(int, input().split())

coins = []
for _ in range(n):
    coins.append(int(input()))

ans = 0
for i in coins[::-1]:
    ans += k // i
    k %= i

print(ans)