#include <iostream>
#include <algorithm>
  
using namespace std;

int N=0, M=0;
int map[500][500] = {0};

void input(){
    cin >> N >> M;
    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            cin >> map[n][m];
        }
    }
}

int __solve_a(){
    int result = -1;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M-3; j++){
            int temp = map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3];
            result = max(result, temp);
        }
    }
    return result;
}

int __solve_b(){
    int result = -1;
    for(int i = 0; i<N-3; i++){
        for(int j = 0; j<M; j++){
            int temp = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
            result = max(result, temp);
        }
    }
    return result;
}

int __solve_c(){
    int result = -1;
    for(int i = 0; i<N-1; i++){
        for(int j = 0; j<M-1; j++){
            int temp = map[i][j] + map[i+1][j] + map[i][j+1] + map[i+1][j+1];
            result = max(result, temp);
        }
    }
    return result;
}
int __solve_d(){
    int result = -1;
    
    for(int i = 0; i<N-1; i++){
        for(int j = 0; j<M-2; j++){
            int temp1 = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2];
            
            int temp2[] = {
                temp1 - map[i][j] - map[i][j+1],        //1,2
                temp1 - map[i][j+1] - map[i][j+2],  //2,3
                temp1 - map[i+1][j] - map[i+1][j+1],      //4,5
                temp1 - map[i+1][j+1] - map[i+1][j+2],    //5,6
                temp1 - map[i][j] - map[i][j+2],      //1,3
                temp1 - map[i+1][j] - map[i+1][j+2],      //4,6
                temp1 - map[i][j] - map[i+1][j+2],        //1,6
                temp1 - map[i][j+2] - map[i+1][j]     //3,4
            };

            int temp3 = *max_element(temp2, temp2 + 8);

            result = max(result, temp3);
        }
    }
    return result;
}

int __solve_e(){
    int result = -1;
    
    for(int i = 0; i<N-2; i++){
        for(int j = 0; j<M-1; j++){
            int temp1 = map[i][j] + map[i][j+1] + map[i+1][j] + map[i+1][j+1] + map[i+2][j] + map[i+2][j+1];
            
            int temp2[] = {
                temp1 - map[i][j] - map[i+1][j],
                temp1 - map[i][j+1] - map[i+1][j+1],

                temp1 - map[i+1][j] - map[i+2][j],
                temp1 - map[i+1][j+1] - map[i+2][j+1],

                temp1 - map[i][j] - map[i+2][j],
                temp1 - map[i][j+1] - map[i+2][j+1],

                temp1 - map[i][j] - map[i+2][j+1],
                temp1 - map[i][j+1] - map[i+2][j]
            };

            int temp3 = *max_element(temp2, temp2 + 8);

            result = max(result, temp3);
        }
    }
    return result;
}

int solve(){
    int arr[] = {
        __solve_a(), 
        __solve_b(), 
        __solve_c(), 
        __solve_d(), 
        __solve_e()
    };

    return *max_element(arr, arr + 5); // max_element는 포인터를 받음
}

int main(){
    //scanf, gets, getchar 같이 사용하지 말 것
    ios::sync_with_stdio(false);
	cin.tie(0);

    //파일 입출력, 제출 시 삭제할것
    //실행파일과 같은 디렉토리에 input.txt파일 읽기기
    freopen("input.txt", "r", stdin);

    input();
    cout << solve() << endl;
    
    return 0;
}