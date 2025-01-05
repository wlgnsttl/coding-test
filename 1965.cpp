//1965 상자넣기
#include <iostream>
#include <algorithm>
  
using namespace std;

int n=0;
int box[1000] = {0};

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> box[i];
    }
}

int bs(){
    int sub[1000] = {0};
    int len = 0;

    for(int i=0; i<n; i++){
        int* pos = lower_bound(sub, sub+len, box[i]);

        if(pos == sub+len){
            sub[len++] = box[i];
        }
        else{
            *pos = box[i];
        }
    }

    return len;
}

int dp(){
    int dp[1000] = {0};
    for(int i=0; i<1000; i++){dp[i]=1;}

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(box[j] < box[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return *max_element(dp,dp+n);
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    freopen("input.txt", "r", stdin);   //제출 시 삭제

    input();
    cout << dp() << endl;

    return 0;
}