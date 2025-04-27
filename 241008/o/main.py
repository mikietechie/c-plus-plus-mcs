# Online Python - IDE, Editor, Compiler, Interpreter
# a, b = map(int, input().split())
# c, d = map(int, input().split())
# e, f = map(int, input().split())
# preans = c * f * b + d * e * b + a * d * f
# ans = (abs(preans / (b * d * f))) ** (1 / 2)
# print(ans)


def main():
    """..."""
    a, b = tuple(map(int, input().split()))
    c, d = tuple(map(int, input().split()))
    e, f = tuple(map(int, input().split()))
    print((abs((c * f * b + d * e * b + a * d * f) / (b * d * f))) ** (1 / 2))


if __name__ == "__main__":
    main()
