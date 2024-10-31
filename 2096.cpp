#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp1[3];
int dp2[3];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        int x1 = dp1[0], x2 = dp1[1], x3 = dp1[2];
        int y1 = dp2[0], y2 = dp2[1], y3 = dp2[2];
        
        dp1[0] = max(x1, x2) + a;
        dp1[1] = max({x1, x2, x3}) + b;
        dp1[2] = max(x2, x3) + c;
        
        dp2[0] = min(y1, y2) + a;
        dp2[1] = min({y1, y2, y3}) + b;
        dp2[2] = min(y2, y3) + c;
    }
    
    cout << max({dp1[0], dp1[1], dp1[2]});
    cout << " ";
    cout << min({dp2[0], dp2[1], dp2[2]});
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    
    return 0;
}