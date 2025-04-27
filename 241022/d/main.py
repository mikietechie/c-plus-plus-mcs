"""..."""


def main():
    """..."""
    n = int(input())
    g = 0
    s = 0

    h = 1
    while h * h <= n:
        if n % h == 0:
            g += 1
        if h * h == n:
            s = 1
        h += 1
    if s == 1:
        print(2 * g - 1)
    else:
        print(2 * g)


if __name__ == "__main__":
    main()
