def solve():
    import sys
    n, m = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    b = list(map(int, sys.stdin.readline().split()))
    
    # Initialize DP table
    dp = [[0.0] * (m + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        for j in range(m + 1):
            if i == 0:
                dp[i][j] = 0.0
            elif j == 0:
                dp[i][j] = 1.0
            else:
                prob = a[i - 1] / (a[i - 1] + b[j - 1])
                dp[i][j] = prob * dp[i - 1][j] + (1 - prob) * dp[i][j - 1]
    
    print("{0:.6f}".format(dp[n][m]))

solve()