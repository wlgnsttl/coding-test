#include <iostream>
using namespace std;

int K, N;

void func(int k, int n){
    if(n==0){
        cout << endl;
        return;
    }
    else{
        for(int i=k; i<=K; i++){
            cout << i << ' ';
            func(i, n-1);
        }
    }
}
int main() {
    cin >> K >> N;

    for(int i=1; i<K; i++){
        func(i, N);
    }

    return 0;
}