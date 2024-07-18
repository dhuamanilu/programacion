from math import sqrt
def solve():
    n = int(input())
    # máximo IQ obtenible con i cabezas en total
    dp = [0] * (n + 1)
    for i in range(n + 1):
        dp[i] = i
    for i in range(3, n + 1):
        for j in range(1, (i//2) + 1 ):
            dp[i] = max(dp[i], dp[i - j] * dp[j])
    print(dp[n])

if __name__ == "__main__":
    solve()




