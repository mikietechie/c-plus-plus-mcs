"""..."""

from __future__ import annotations
from dataclasses import dataclass


@dataclass
class Point:
    """..."""

    x: int
    y: int

    @staticmethod
    def input():
        """..."""
        x, y = tuple(map(int, input().split()))
        return Point(x=x, y=y)

    def __str__(self):
        return f"<x:{self.x}, y:{self.y}>"

    @staticmethod
    def get_distance(p1: Point, p2: Point):
        """..."""
        return (pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)) ** (1 / 2)

    @staticmethod
    def points_between(p1: Point, p2: Point):
        """..."""
        x_step = 1 if p2.x > p1.x else -1
        y_step = 1 if p2.y > p1.y else -1
        distance = Point.get_distance(p1, p2)
        k = 0
        for x in range(p1.x, p2.x + x_step, x_step):
            for y in range(p1.y, p2.y + y_step, y_step):
                p = Point(x, y)
                if (
                    Point.get_distance(
                        p1,
                        p,
                    )
                    + Point.get_distance(
                        p2,
                        p,
                    )
                    == distance
                ):
                    k += 1
        return k


def main():
    """..."""
    p1 = Point.input()
    p2 = Point.input()
    print(Point.points_between(p1, p2))


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        pass
