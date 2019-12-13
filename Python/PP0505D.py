# https://pl.spoj.com/problems/PP0505D/


def gray(num):
    result = ['0', '1']
    for i in range(num - 1):
        n = len(result)
        result = result + result[::-1]
        for j in range(n):
            result[j] = '0' + result[j]
        for j in range(n, 2 * n):
            result[j] = '1' + result[j]
    return result


n = int(input())

for i in range(n):
    num = int(input())
    for i in gray(num):
        print(i)
