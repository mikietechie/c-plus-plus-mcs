import sys
import math


def solve():
    n = int(sys.stdin.readline())
    rates = []
    for _ in range(n):
        row = list(map(float, sys.stdin.readline().split()))
        rates.append(row)

    # Convert to logarithms for Bellman-Ford
    log_rates = [[0.0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            log_rates[i][j] = -math.log(rates[i][j])

    # Bellman-Ford to detect negative cycles
    dist = [0.0] * n
    parent = [-1] * n
    for _ in range(n):
        updated = False
        for u in range(n):
            for v in range(n):
                if dist[v] > dist[u] + log_rates[u][v]:
                    dist[v] = dist[u] + log_rates[u][v]
                    parent[v] = u
                    updated = True
        if not updated:
            break
    else:
        # Negative cycle found
        print("YES")
        # Find the cycle
        for u in range(n):
            for v in range(n):
                if dist[v] > dist[u] + log_rates[u][v]:
                    cycle = []
                    visited = set()
                    current = v
                    while current not in visited:
                        visited.add(current)
                        cycle.append(current + 1)  # 1-based index
                        current = parent[current]
                        if current == -1:
                            break
                    cycle_start = cycle.index(current + 1)
                    print(
                        " ".join(
                            map(
                                str,
                                cycle[cycle_start:] + [cycle[cycle_start]],
                            ),
                        )
                    )
                    return
    print("NO")


solve()
