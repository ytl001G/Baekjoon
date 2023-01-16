def solution(I):
    n = len(I)
    
    state = [0]
    ans = 0
    for i in range(n):
        if I[i] == 1:
            if state[-1] == 3:
                ans += 1
                state.pop()
            else:
                state.append(1)
        
        if I[i] == 2:
            if state[-1] == 1:
                state[-1] = 2
            else:
                state.append(0)

        if I[i] == 3:
            if state[-1] == 2:
                state[-1] = 3
            else:
                state.append(0)
        
    return ans
        