while True:
    a = input()
    if a == '.':
        break
    
    yesno = 'no'
    stack = []
    for x in a:
        if x == '(':
            stack.append(1)
        if x == '[':
            stack.append(2)
        if x == ')':
            if stack and stack[-1] == 1:
                stack.pop()
            else:
                stack.append(3)
                break
        if x == ']':
            if stack and stack[-1] == 2:
                stack.pop()
            else:
                stack.append(3)
                break
    
    if not stack:
        yesno = 'yes'
    
    print(yesno)