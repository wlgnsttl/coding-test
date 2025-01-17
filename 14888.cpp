#include <iostream>
#include <algorithm>
  
using namespace std;


int N;
int arr[100] = {0};
int oper[4] = {0};

int max_val = -1000000001;
int min_val = 1000000001;

void input(){
    cin >> N;
    for(int i=0; i<N; i++){cin >> arr[i];}
    for(int i=0; i<4; i++){cin >> oper[i];}
}

int sum(int arr[]){
    int ret = 0;
    for(int i=0; i<4; i++){ret+=arr[i];}
    return ret;
}

void solve(int val, int depth, int oper_arr[]){
    if(depth == N-1){
        max_val = max(max_val, val);
        min_val = min(min_val, val);
        return;
    }

    for(int i=0; i<4; i++){
        if(oper_arr[i]>0){
            oper_arr[i]--;
            if(i==0){
                solve(val+arr[depth+1], depth+1, oper_arr);
            }
            else if(i==1){
                solve(val-arr[depth+1], depth+1, oper_arr);
            }
            else if(i==2){
                solve(val*arr[depth+1], depth+1, oper_arr);
            }
            else if(i==3){
                solve(val/arr[depth+1], depth+1, oper_arr);

            }
            oper_arr[i]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    freopen("input.txt", "r", stdin);   //제출 시 삭제

    input();
    solve(arr[0], 0, oper);
    cout << max_val << '\n';
    cout << min_val << '\n';

    return 0;
}