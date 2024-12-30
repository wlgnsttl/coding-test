#include <iostream>
#include <cmath>
  
using namespace std;

int N=0, B=0, C=0;
int A[1000001] = {0};

void input(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> A[i];
    }
    cin >> B >> C;
}

int __solve(int numb_A){
    int result = 1;

    double temp = numb_A- B;

    if(temp <= 0){return result;}

    temp = temp/double(C);

    result += ceil(temp);

    return result;
}

long long solve(){
    long long result = 0;

    for(int i=1; i<= N; i++){
        result += __solve(A[i]);
    }

    return result;
}

int main(){
    //C 와 C++ 의 버퍼를 분리해 입력을 더 빠르게 한다
    //scanf, gets, getchar 같이 사용하지 말 것
    ios::sync_with_stdio(false);
	cin.tie(0);

    //파일 입출력, 제출 시 삭제할것
    //실행파일과 같은 디렉토리에 input.txt파일을 읽는다
    freopen("input.txt", "r", stdin);
    
    input();
    cout << solve() << '\n';

    return 0;
}