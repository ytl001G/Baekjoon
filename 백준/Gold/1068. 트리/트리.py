n = int(input())
nodes = [True for _ in range(n)]
connections = []

for i, s in enumerate(map(int, input().split())):
    if s == -1:
        continue
    else:
        connections.append( (s,i) ) # parents, child

# delete on node
def deletenode(idx):
    global nodes, connections
    nodes[idx] = False
    
    for c in connections:
        if c[0] == idx:
            deletenode(c[1])

deletenode(int(input()))

def isleaf(idx):
    global nodes, connections
    for c in connections:
        if c[0] == idx and nodes[c[1]]:
            return False
    
    return True

ans = 0
for i in range(n):
    if nodes[i] and isleaf(i):
        ans += 1
        
print(ans)