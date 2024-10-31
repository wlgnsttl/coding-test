#include <iostream>
#include <vector>

using namespace std;

struct NODE{
    int data = 0;
    int left = 0;
    int right = 0;
};

typedef struct NODE node;
 
node arr[1000001];

void append_tree(node &n, int temp){
    if(temp < n.data){
        if(n.left == 0){
            n.left = temp;
            arr[temp].data = temp;
            return;
        }
        else{
            append_tree(arr[n.left], temp);
        }
    }
    else if(temp > n.data){
        if(n.right == 0){
            n.right = temp;
            arr[temp].data = temp;
            return;
        }
        else{
            append_tree(arr[n.right], temp);
        }
    }
}

void last_order(node n){
    if(n.left != 0){
        last_order(arr[n.left]);
    }
    if(n.right != 0){
        last_order(arr[n.right]);
    }
    cout << n.data << '\n';
}

int main(){

    //파일 입출력 코드 제출시 삭제할것
    //freopen("input.txt", "r", stdin);

    int temp, root=0;

    //이진트리 생성
    while(cin >> temp){
        if(root == 0){
            root = temp;
            arr[temp].data = temp;
        }
        else{
            append_tree(arr[root], temp);
        }
    }

    last_order(arr[root]);

    return 0;
}