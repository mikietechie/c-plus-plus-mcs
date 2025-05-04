"""..."""

from __future__ import annotations

from dataclasses import dataclass


@dataclass
class Pair:
    """..."""

    first: int
    second: int
    index: int

    def __lt__(self, p: Pair):
        if self.first < p.first:
            return True
        if self.first == p.first and self.index < p.index:
            return True
        return False

    def __str__(self):
        return f"{self.first} {self.second}"


def main():
    """..."""
    n = int(input())
    pairs: list[Pair] = []
    for i in range(n):
        first, second = map(int, input().split())
        pairs.append(Pair(first=first, second=second, index=i))
    pairs.sort()
    for p in pairs:
        print(p)


if __name__ == "__main__":
    main()
