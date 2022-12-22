n,m = map(int, input().split())

window = [[0 for _ in range(n)] for _ in range(m)]

def manhattan_distance(x1,y1, x2,y2):
    return abs(x1-x2) + abs(y1-y2)

for i in range(n):
    row = input()
    for j in range(m):
        window[j][i] = row[j]

min = 1e100
for x in range(m-7):
    for y in range(n-7):
        countB = 0
        for x_ in range(x,x+8):
            for y_ in range(y,y+8):
                md = manhattan_distance(x,y,x_,y_)
                
                if md%2:
                    countB += 1 if ('B' == window[x_][y_]) else 0
                else:
                    countB += 1 if ('B' != window[x_][y_]) else 0
                
                if countB > min:
                    break
            if countB > min:
                break
        
        if countB < min:
            min = countB
            

        countW = 0
        for x_ in range(x,x+8):
            for y_ in range(y,y+8):
                md = manhattan_distance(x,y,x_,y_)
                
                if md%2:
                    countW += 1 if ('W' == window[x_][y_]) else 0
                else:
                    countW += 1 if ('W' != window[x_][y_]) else 0
                
                if countW > min:
                    break
            if countW > min:
                break
        
        if countW < min:
            min = countW

print(min)
            