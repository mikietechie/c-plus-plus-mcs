"""..."""


def main():
    """..."""
    _, n = tuple(map(int, input().split()))
    numbers = list(map(int, input().split()))
    sums = []
    for _ in range(n):
        start, end = tuple(map(int, input().split()))
        sums.append(str(sum(numbers[start-1:end])))
    print("\n".join(sums))


if __name__ == "__main__":
    main()
