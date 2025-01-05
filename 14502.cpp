//14502 연구소
#include <iostream>
#include <queue>
  
using namespace std;

int N=0, M=0, result = -1;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
int map[9][9] = {0,};
vector<pair<int,int>> nv;
vector<pair<int,int>> vv;

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){vv.push_back({i,j});}
            else if(map[i][j] == 0){ nv.push_back({i,j});}
        }
    }
}

int __solve(int a, int b, int c){
    int tmp_map[9][9];
    int tmp_result = nv.size() - 3;
    for(int i=0; i<N; ++i){
        copy(begin(map[i]), end(map[i]), begin(tmp_map[i]));
    }
    tmp_map[nv[a].first][nv[a].second] = 1;
    tmp_map[nv[b].first][nv[b].second] = 1;
    tmp_map[nv[c].first][nv[c].second] = 1;

    queue<pair<int,int>> q;
    for(size_t i=0; i<vv.size(); i++){
        q.push(vv[i]);
    }
    while(!q.empty()){
        pair<int,int> pos = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];

            if(nx<0 || ny<0 || nx>=N || ny>=M || tmp_map[nx][ny] != 0){continue;}

            tmp_map[nx][ny] = 2;
            tmp_result--;
            q.push({nx, ny});
            if(tmp_result <= result){return -1;}
        }
    }
    return tmp_result;
}

void solve(){
    int numb_nv = nv.size();

    for(int i=0; i<numb_nv; i++){
        for(int j=i+1; j<numb_nv; j++){
            for(int k=j+1; k<numb_nv; k++){
                int temp = __solve(i,j,k);
                if(temp > result){result = temp;}
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    freopen("input.txt", "r", stdin);   //제출 시 삭제

    input();
    solve();
    cout << result << '\n';

    return 0;
}