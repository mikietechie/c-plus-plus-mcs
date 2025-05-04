"""..."""

def solve():
    """..."""
    t = int(input())
    output = []
    for _ in range(t):
        x, y = map(int, input().split())
        found = False
        current = x
        for _ in range(32):
            if current == y:
                found = True
                break
            current = (current * 2) % (1 << 32)
        if not found:
            current = x
            for _ in range(32):
                if current == y:
                    found = True
                    break
                current = current // 2
        output.append("Yes" if found else "No")
    print("\n".join(output))


solve()
