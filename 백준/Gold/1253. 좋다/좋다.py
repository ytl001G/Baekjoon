n = int(input())
num = list(map(int, input().split()))
num.sort()

ans = 0
for i in range(n):
  temp = num[:i] + num[i+1:]
  left = 0
  right = len(temp)-1

  while left < right:
    if num[i] < temp[left] + temp[right]:
      right -= 1
    elif num[i] > temp[left] + temp[right]:
      left += 1
    else:
      ans += 1
      break
  
print(ans)