#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    //파일 입출력, 제출시 삭제할것
    freopen("input.txt", "r", stdin);

    int n;
    vector<string> v;
    string result = "";
    cin >> n;
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        v.push_back(temp);
    }

    for(int i=0; i<v[0].length(); i++){
        char temp = v[0][i];
        for(int j=0; j<v.size(); j++){
            if(temp != v[j][i]){
                temp = '?';
                break;
            }
        }
        result += temp;
    }

    cout << result;


    return 0;
}