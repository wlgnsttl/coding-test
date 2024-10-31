#include <iostream>
  
using namespace std;

int main(){
    //C 와 C++ 의 버퍼를 분리해 입력을 더 빠르게 한다
    //scanf, gets, getchar 같이 사용하지 말 것
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    //파일 입출력, 제출 시 삭제할것
    //실행파일과 같은 디렉토리에 input.txt파일을 읽는다
    freopen("input.txt", "r", stdin);

    

    return 0;
}