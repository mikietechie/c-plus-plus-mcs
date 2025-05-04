"""..."""

from collections import deque


def reverse_bits(x: int):
    """..."""
    reversed_x = 0
    for i in range(32):
        if x & (1 << i):
            reversed_x |= 1 << (31 - i)
    return reversed_x


def min_operations(n: int):
    """..."""
    visited = set()
    queue = deque()
    queue.append((0, 0))
    visited.add(0)

    while queue:
        current, steps = queue.popleft()
        if current == n:
            return steps
        # Operation 1: Add 1
        next_num = (current + 1) % (1 << 32)
        if next_num not in visited:
            visited.add(next_num)
            queue.append((next_num, steps + 1))
        # Operation 2: Reverse bits
        reversed_num = reverse_bits(current)
        if reversed_num not in visited:
            visited.add(reversed_num)
            queue.append((reversed_num, steps + 1))
    return -1


def main():
    """..."""
    n = int(input())
    print(min_operations(n))


if __name__ == "__main__":
    main()
