dx = [0,0,1,-1]
dy = [1,-1,0,0]

n = int(input())

window = []
ans = [0,0]

for _ in range(n):
    window.append(list(map(int, list(input()))))
    
def dfs(x, y, p):
    ans[p] += 1
    window[x][y] = p
    
    for i in range(4):
        if 0 <= x+dx[i] < n and 0 <= y+dy[i] < n and window[x+dx[i]][y+dy[i]] == 1:
            dfs(x+dx[i], y+dy[i], p)

p = 2
for x in range(n):
    for y in range(n):
        if window[x][y] == 1:
            ans.append(0)
            dfs(x, y, p)
            p += 1

ans = ans[2:]
ans.sort()

print(len(ans))
for i in range(len(ans)):
    print(ans[i])
            