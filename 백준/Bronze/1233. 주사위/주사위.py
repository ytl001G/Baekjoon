S1, S2, S3 = map(int, input().split(' '))
dice_sum = [0]*81


for i in range(1,S1+1):
  for j in range(1,S2+1):
    for k in range(1,S3+1):
      dice_sum[i+j+k] += 1

dice_max = max(dice_sum)

i=0
while True:
  if dice_sum[i] == dice_max:
    print(i)
    break
  i+=1
