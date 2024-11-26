"""Task 1"""


def move(a: int, b: int, d: int) -> int:
    """Doc"""
    next_n: int = a + d
    if next_n >= b:
        return b
    return next_n
