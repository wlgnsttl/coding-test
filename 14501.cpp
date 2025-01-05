//14501 퇴사
#include <iostream>
  
using namespace std;

int N=0;
pair<int,int> calendar[16] = {};
int dp[16] = {0};
int result = -1;

void input(){
    cin >> N;
    for(int i=1; i<=N; i++){
        int t=-1, p=-1;
        cin >> t >> p;
        calendar[i] = {t,p}; 
    }
}

void solve(int t, int p){
    if(result < p){result = p;}
    for(int i=t; i<=N; i++){
        if(i+calendar[i].first <= N+1 ){
            solve(i+calendar[i].first, p+calendar[i].second);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    //freopen("input.txt", "r", stdin);   //제출 시 삭제

    input();
    solve(1,0);
    cout << result << endl;

    return 0;
}