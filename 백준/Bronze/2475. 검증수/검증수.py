l = list(map(int, input().split()))

ans = 0
for x in l:
    ans = (ans + x**2)%10
    
print(ans)