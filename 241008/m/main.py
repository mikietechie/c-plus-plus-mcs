# Online Python - IDE, Editor, Compiler, Interpreter
# a, b, x1, x2 = map(int, input().split())

# if(x1>x2):
#  print(a+1/b)
# else:
#  print(-(a+1/b))


def main():
    """..."""
    a, b, x_1, x_2 = [int(i) for i in input().split()]
    if x_1 > x_2:
        print(a + 1 / b)
    else:
        print(-(a + 1 / b))


if __name__ == "__main__":
    main()
