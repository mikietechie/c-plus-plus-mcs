"""...."""

a, b, x1, x2 = list(map(int, input().split()))


def func(x: int):
    """..."""
    return (a * x) + (x / b)


ans = func(x1) - func(x2)
if isinstance(ans, float) and (ans == int(ans)):
    ans = int(ans)

print(ans)
