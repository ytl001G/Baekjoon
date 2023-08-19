def gcd(a, b):
    if a == 0:
        return b
    return gcd(b%a, a)

T = int(input())

for t in range(T):
    a, b = map(int, input().split())
    lcm = int(a*b/gcd(a,b))
    print(lcm)