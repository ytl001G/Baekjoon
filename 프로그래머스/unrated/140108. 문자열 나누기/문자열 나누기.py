def solution(s):
    n = len(s)
    
    x_id = 0
    is_x = 0
    not_x = 0
    ans = 0
    for i in range(n):
        if s[i] == s[x_id]:
            is_x += 1
        else:
            not_x += 1
        
        if is_x == not_x:
            ans += 1
            x_id = i+1
            is_x = 0
            not_x = 0
            
    if is_x + not_x != 0:
        ans += 1
    
    return ans