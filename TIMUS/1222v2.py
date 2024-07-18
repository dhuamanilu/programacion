from math import sqrt
def solve2(n):
    dp = [0] * (n + 1)
    dp[0]=0
    dp[1]=1
   
    for i in range(2,n + 1):
        #print(i)
        #print("que fue xd",i,dp)
        if((i%3)==1):
            cant=(i-4)//3
            ans=(3 ** cant) * 4
            dp[i]=ans
        elif ((i%3)==2):
            cant=(i-2)//3
            ans=(3 ** cant) * 2
            dp[i]=ans
        else:
            cant=i//3
            ans=(3 ** cant)
            dp[i]=ans
    return dp[n]
    
def solve(n):
    
    # máximo IQ obtenible con i cabezas en total
    dp = [0] * (n + 1)
    for i in range(n + 1):
        dp[i] = i
    for i in range(3, n + 1):
        for j in range(1, (i//2) + 1 ):
            dp[i] = max(dp[i], dp[i - j] * dp[j])

    return dp

if __name__ == "__main__":
    n = int(input())
    ans = solve2(n)
    print(ans)
    
