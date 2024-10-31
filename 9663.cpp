#include <iostream>
#include <cmath>

#define MAX 15

using namespace std;

int n, count = 0;
int map[MAX];

/*
(index, map[index])가 존재할 수 있는지 판단한다
*/
bool check(int index){

    //index전까지의 퀸의 위치를 모두 확인한다
    //(index, map[index])에 퀸이 존재할 수 없다면 false를 return
    for(int i=0; i<index; i++){
        //(i,map[i])와 (index, map[index]) 위치 비교
        if(abs(i-index) == abs(map[i]-map[index]) || map[index] == map[i]){
            return false;
        }
    }
    //존재할 수 있다면 true를 return
    return true;
}

/*
index행에 퀸을 두는 함수이다
만약 index행에 퀸을 둘 수 있다면 다음 행으로 넘어간다
n개 만큼 놓았다면 count를 증가하고 함수를 빠져나온다
*/
void solve(int index){
    //index가 n-1까지 연산이 끝나 n이 되어 들어왔다면 case하나를 완성한 것으로 보고 count 1 증가
    if(index == n){
        count++;
        return;
    }

    for(int i=0; i<n; i++){
        //현재 index행에서 모든 자리에 퀸을 놓아본다
        map[index] = i;
        if(check(index) == true){
            //둔 퀸이 존재할 수 있으면 다음 행으로 넘어간다
            solve(index+1);
        }
    }
}

int main(){
    //C 와 C++ 의 버퍼를 분리해 입력을 더 빠르게 한다
    //scanf, gets, getchar 같이 사용하지 말 것
    ios::sync_with_stdio(false);
	cin.tie(0);

    //파일 입출력, 제출 시 삭제할것
    //실행파일과 같은 디렉토리에 input.txt파일을 읽는다
    freopen("input.txt", "r", stdin);

    //in
    cin >> n;

    //solve
    solve(0);

    //out
    cout << count << '\n';

    return 0;
}