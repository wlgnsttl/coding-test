#include <iostream>
#include <algorithm>
#include <vector>
  
using namespace std;

int N, result = 100;
int stat[21][21] = {0};

void input(){
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> stat[i][j];
        }
    }
}

int calc_stat(const vector<int> v){
    int res = 0;
    for(int i : v){
        for(int j : v){
            if(i==j){continue;}
            else{
                res += stat[i][j];
            }
        }
    }
    return res;
}

void __solve(vector<bool> vec, int length){
    vector<int> start;
    vector<int> link;

    for(int i=0; i<length; i++){
        if(vec[i]){
            start.push_back(i+1);
        }
        else{
            link.push_back(i+1);
        }
    }

    int a = calc_stat(start);
    int b = calc_stat(link);

    int temp = abs(a-b);
    result = min(result, temp);
}

void solve(){
    vector<bool> vec(N,0);
    fill(vec.begin(), vec.begin()+N/2, 1);

    do{
        __solve(vec, N);
    }while(prev_permutation(vec.begin(), vec.end()));
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    freopen("input.txt", "r", stdin);   //제출 시 삭제

    input();
    solve();
    cout << result << '\n';

    return 0;
}