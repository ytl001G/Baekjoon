def solution(people, limit):
    people.sort()
    
    ans = 0
    
    l = 0
    r = len(people)-1
    
    while l < r:
        temp = people[l] + people[r]
        
        if temp <= limit:
            l += 1
        r -= 1
        
        ans += 1

    if l == r:
        ans += 1
        
    return ans