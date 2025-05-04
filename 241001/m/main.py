"""..."""


def main():
    """..."""
    _, x = map(int, input().split())
    arr = set(map(int, input().split()))
    for a in arr:
        if x - a in arr:
            print("YES")
            return

    print("NO")


if __name__ == "__main__":
    main()
