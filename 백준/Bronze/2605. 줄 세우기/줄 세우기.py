n = int(input())
A = list(map(int, input().split()))

ans = []
for i in range(n):
    ans.insert(len(ans)-A[i] ,i+1)

print(' '.join(map(str, ans)))