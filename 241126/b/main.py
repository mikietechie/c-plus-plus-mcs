"""..."""

import math


def main():
    """..."""
    num = int(input())
    red = 2
    blue = 3
    ceil = num  # math.ceil(num / blue)
    store = set()
    for bi in range(ceil):
        blues = bi * blue
        for ri in range(ceil):
            reds = ri * red
            length = reds + blues
            if length == num:
                store.add(f"{bi}b:{ri}r")
    print(len(store))


if __name__ == "__main__":
    main()
