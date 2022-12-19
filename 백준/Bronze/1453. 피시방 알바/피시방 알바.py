N = int(input())
sit = [True]*(101)
sit_p = list(map(int, input().split(' ')))
reject = 0

for i in range(N):
  if sit[sit_p[i]]:
    sit[sit_p[i]] = False
  else:
    reject += 1

print(reject)
