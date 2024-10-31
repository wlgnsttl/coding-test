#include <iostream>
#include <string>

using namespace std;    

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    //파일 입출력, 제출시 삭제할것
    //freopen("input.txt", "r", stdin);

    int tc, result = 0;
    cin >> tc;

    for(int tc_iter = 0; tc_iter < tc; tc_iter++){
        string s;
        cin >> s;

        if(s.length() == 1){
            continue;
        }

        bool visit[30] = {0};

        for(int i=0; i<s.length(); i++){
            char temp = s[i];

            if(visit[int(temp) - 'a'] == true){
                result++;
                break;
            }

            if(temp == s[i+1]){
                for(i; i<s.length(); i++){
                    if(temp != s[i+1]){
                        break;
                    }
                }
            }

            visit[int(temp - 'a')] = true;
        }

    }
    cout << tc-result << '\n';

    return 0;
}