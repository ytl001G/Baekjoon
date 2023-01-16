def solution(n, lost, reserve):
    reserve_used = []
    
    ans = 0
    for i in range(1,n+1):
        if i in lost:
            if i in reserve:
                ans += 1
                
            else:
                if i-1 in reserve and i-1 not in lost and i-1 not in reserve_used:
                    reserve_used.append(i-1)
                    ans += 1
                elif i+1 in reserve and i+1 not in lost and i+1 not in reserve_used:
                    reserve_used.append(i+1)
                    ans += 1
        
        else:
            ans += 1
    
    return ans