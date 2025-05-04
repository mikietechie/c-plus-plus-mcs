def solve():
    n = int(input())
    p = list(map(int, input().split()))
    max_mod = 0
    for mask in range(1, 1 << n):
        product = 1
        for i in range(n):
            if mask & (1 << i):
                product *= p[i]
        mod = product % (1 << 30)
        if mod > max_mod:
            max_mod = mod
    print(max_mod)


solve()
