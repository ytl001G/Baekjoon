def solution(order):
    n = len(order)
    main = [i for i in range(n,0,-1)]
    sub = []
    
    ans = 0
    for i in order:
        if len(main) > 0 and main[-1] <= i:
            while True:
                if main[-1] == i:
                    break
                    
                sub.append(main[-1])
                main.pop()
            
            main.pop()
            ans += 1
        else:
            if len(sub) > 0 and sub[-1] == i:
                sub.pop()
                ans += 1
            else:
                break
    
    return ans