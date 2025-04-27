# # Online Python - IDE, Editor, Compiler, Interpreter
# n = int(input())
# m  = [int(s) for s in input().split()]
# c = sum(m)
# for j in range(n):
#  c=c +1/m[j]

# print(c)


def main():
    """..."""
    int(input())
    numbers = list(map(int, input().split()))
    ans = sum(numbers)
    for num in numbers:
        ans = ans + (1 / num)
    print(ans)


if __name__ == "__main__":
    main()
