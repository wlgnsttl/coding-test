#include <iostream>
#include <queue>
#define MAX 100000
#define INF 987654321

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    //파일 입출력, 제출시 삭제할것
    freopen("input.txt", "r", stdin);

    queue<int> q;
    int visit[MAX+1];
    for(int i=0; i<MAX+1; i++) visit[i] = INF;

    int a, b;
    cin >> a >> b;

    q.push(a);
    visit[a] = 0;

    while(!q.empty()){
        int cur = q.front();
        int cur_time = visit[cur];
        q.pop();

        if(cur*2 <= MAX){
            if(visit[cur*2] > cur_time){
                q.push(cur*2);
                visit[cur*2] = cur_time;
            }
        }
        if(cur+1 <= MAX){
            if(visit[cur+1] >= cur_time+1){
                q.push(cur+1);
                visit[cur+1] = cur_time+1;
            }
        }
        if(cur-1 >= 0){
            if(visit[cur-1] >= cur_time+1){
                q.push(cur-1);
                visit[cur-1] = cur_time+1;
            }
        }

    }

    cout << visit[b] << '\n';
    return 0;
}