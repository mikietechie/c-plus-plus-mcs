"""..."""

import struct


def main():
    """..."""
    p, q = tuple(map(int, input().split()))
    num = p / q
    binary = " ".join(f"{c:0>8b}" for c in struct.pack("!f", num))
    hexadecimal = " ".join(f"{c:0>2x}" for c in struct.pack("!f", num))
    print(binary)
    print(hexadecimal.upper())


if __name__ == "__main__":
    main()
