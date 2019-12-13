# https://pl.spoj.com/problems/EUCGAME/

n = int(input())

for i in range(n):
    a, b = map(int, input().split())
    while a != b:
        if a < b:
            b -= a
        else:
            a -= b
    print(a + b)
