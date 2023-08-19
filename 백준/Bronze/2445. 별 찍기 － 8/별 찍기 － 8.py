a = int(input())

for i in range(a*2-1):
    for j in range(a*2):
        if i < a:
            if j <= i or j >= a*2-i-1:
                print('*',end='')
            else:
                print(' ',end='')
        elif i == a-1:
            print('*'*(a*2),end='')
            break
        else:
            if j < a*2-i-1 or i < j:
                print('*',end='')
            else:
                print(' ',end='')

    print()