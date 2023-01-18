n = int(input())

A = list(map(int, input().split()))

l = 0
r = 1
ans = 0
if len(A) == 1:
    print(0)
else:
    while r < len(A):
        if A[l]&1 != A[r]&1:
            r += 1
        else:
            ans += r-l-1
            l += 1
            r += 1
            
    print(ans)