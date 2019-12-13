# https://pl.spoj.com/problems/BFN1/


def reverse(word):
    word = str(word)
    return word[::-1]


def is_palindrome(word):
    word = str(word)
    return word == word[::-1]


def add_reverse(num):
    reversed = int(reverse(num))
    return num + reversed


n = int(input())

for i in range(n):
    num = int(input().strip())
    count = 0
    while not is_palindrome(num):
        num = add_reverse(num)
        count += 1
    print(num, count)
