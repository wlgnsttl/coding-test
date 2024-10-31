#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001
#define INF 987654321
using namespace std;

int n, m;
char map[MAX][MAX];
int visit[MAX][MAX][2];

void input(){
    //데이터 입력
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
        }
    }
    //visit 모든 요소를 INF로 초기화한다
    //벽을 부수지 않고 이동한 경우도 저장해야하므로 3차원 배열로 선언한다
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            visit[i][j][0] = INF;
            visit[i][j][1] = INF;
        }
    }
}

int solve(){
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    queue<pair<int,int>> q;

    visit[1][1][0] = 1;
    q.push({1,1});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        //현재 요소가 벽을 부수고왔는지 판단하기 위한 변수
        bool broken = false; 
        q.pop();

        if(x < 0){
            //만약 x값이 음수이면 벽을 부수고 온 것으로 판단한다
            broken = true;
            x = -x;
        }

        for(int i=0; i<4; i++){
            //현재 위치에서 상하좌우 이동
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <= 0 || nx > n || ny <= 0 || ny > m){
                //map바깥으로 나갔을 경우 continue한다
                continue;
            }
            if(map[nx][ny] == '1' && broken == true){
                //벽을 이미 부수고 왔고, 벽을 만났으면 continue한다
                continue;
            }

            if(map[nx][ny] == '1' && broken == false){
                //벽을 아직 부수지 않았고, 벽을 만났을 경우 벽을 부순다
                if(visit[nx][ny][1] > visit[x][y][0] + 1){
                    visit[nx][ny][1] = visit[x][y][0] + 1;
                    //벽을 부쉈으므로 x값을 음수로 push한다
                    q.push({-nx,ny});
                }
            }

            //벽을 만나지 않았을 때이다
            else if(map[nx][ny] == '0' && broken == false){
                //벽을 아직 부수지 않은 경우이다
                if(visit[nx][ny][0] > visit[x][y][0] + 1){
                    visit[nx][ny][0] = visit[x][y][0] + 1;
                    q.push({nx,ny});
                }
            }
            else if(map[nx][ny] == '0' && broken == true){
                //벽을 부수고 온 경우이다
                if(visit[nx][ny][1] > visit[x][y][1] + 1){
                    visit[nx][ny][1] = visit[x][y][1] + 1;
                    q.push({-nx,ny});
                }
            }
        }
    }

    int result = min(visit[n][m][0], visit[n][m][1]); //visit의 벽을 부수고 온 경우와 그렇지 않은 경우 중 최단거리를 대입한다

    if(result == INF){
        //만약 도달하지 못했다면 -1을 리턴한다
        result = -1;
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

    //in
    input();
    
    //out
    cout << solve() << '\n';

    return 0;
}