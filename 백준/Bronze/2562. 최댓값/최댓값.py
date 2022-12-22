max = 0
maxid = -1
for i in range(9):
    n = int(input())
    
    if n > max:
        max = n
        maxid = i+1
        
print(max)
print(maxid)