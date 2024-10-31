#include <iostream>
#include <algorithm>

#define MAX 1000001

using namespace std;

int solve()
{
    
    //2xMAX 배열에 값 입력
    int n = 0;
    int map[2][MAX] = {0,};
    int dp[2][MAX] = {0,};
    
    cin >> n;
    
    for(int i=1; i<=n; i++)
    {
        int temp;
        cin >> temp;
        map[0][i] = temp;
    }
    for(int i=1; i<=n; i++)
    {
        int temp;
        cin >> temp;
        map[1][i] = temp;
    }
    
    //DP를 이용한 솔루션
    
    
    //dp[0][0] = dp[0][1] = 0
    dp[0][1] = map[0][1];
    dp[1][1] = map[1][1];
    
    for(int i=2; i<n+1; i++)
    {
        dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + map[0][i];
        dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + map[1][i];
    }
    
    
    return max(dp[0][n], dp[1][n]);
}

int main()
{
    int tc;
    
    
    cin >> tc;
    
    while(tc--)
    {
        cout << solve() << '\n';
    }

    return 0;
}