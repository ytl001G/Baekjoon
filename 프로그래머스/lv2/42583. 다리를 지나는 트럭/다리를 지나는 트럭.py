def solution(bridge_length, weight, truck_weights):
    wating = truck_weights.copy()
    bridge = [0]*bridge_length

    ans = 0
    while wating or sum(bridge):
        if wating and sum(bridge[1:]) + wating[0] <= weight:
            bridge = bridge[1:] + [wating.pop(0)]
            ans += 1
            
        else:
            for i in range(len(bridge)):
                if bridge[i] != 0:
                    bridge = bridge[i+1:] + [0]*(i+1)
                    if wating and sum(bridge) + wating[0] <= weight:
                        bridge[-1] = wating.pop(0)
                    ans += i+1
                    break
        
    return ans