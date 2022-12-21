s = input()
sub = set()

for i in range(len(s)):
  for j in range(i,len(s)):
    substr = s[i:j+1]
    sub.add(substr)

print(len(sub))