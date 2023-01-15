n = int(input())

data = []
for _ in range(n):
    a,b,c,d = map(int, input().split())
    
    data.append( (max(100*a+b, 301), 100*c+d) )

data.sort()

# for i in range(n):
#     print(i, data[i])

if data[0][0] > 301:
    print(0)

else:
    max_id = 0
    new_max_id = 0
    cnt = 1
    for i in range(n):
        if data[max_id][1] > 1130: break
        
        if data[i][0] == 301 and data[i][1] >= data[max_id][1]:
            max_id = i
        
        else:
            # print(i, max_id, data[max_id][1])
            
            if data[i][0] <= data[max_id][1] and data[i][1] >= data[new_max_id][1]:
                new_max_id = i
                
            if i == n-1 or data[i+1][0] > data[max_id][1]:
                max_id = new_max_id
                cnt += 1
                
    if data[max_id][1] > 1130:
        print(cnt)
    else:
        print(0)