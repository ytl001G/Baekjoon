import sys

n = sys.stdin.readline()[:-1]
if int(n) == 0:
  print(0)
else:
  trans = ['000','001','010','011','100','101','110','111']
  ans = ''
  for i in range(len(n)):
    if i == 0 and int(n[i])<4:
      last = trans[int(n[i])]
      if 2<=int(n[i]):
        ans += last[1:]
      elif int(n[i])==1:
        ans += last[2]
    else:
      ans += trans[int(n[i])]

  print(ans)