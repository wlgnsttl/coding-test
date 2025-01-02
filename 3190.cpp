#include <iostream>
#include <vector>
#include <queue>
  
using namespace std;

int N=0, K=0, L=0;
int map[101][101] = {0,};
queue<pair<int, char>> dir_map;
pair<int,int> tail;
const int dx[5] = {-999, 0, 1, 0, -1};
const int dy[5] = {-999, 1, 0, -1, 0};

void input(){
    cin >> N;
    cin >> K;
    for(int i=0; i<K; i++){
        int row=0, col=0;
        cin >> row >> col;
        map[row][col] = -1;
    }
    cin >> L;
    for(int i=0; i<L; i++){
        int time=0;
        char dir_symb=0;
        cin >> time >> dir_symb;
        dir_map.push({time, dir_symb});
    }
}

bool is_over(int x, int y){
    return (x<1 || y<1 || x>N || y>N || map[x][y]>0);
}

int next_dir(int cur_dir, char change_symb){
    int next = cur_dir;
    if(change_symb == 'D'){ next++; }
    else{ next--; }

    if(next == 0) { next = 4;}
    if(next == 5) { next = 1;}
    return next;
}

void disp(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(map[i][j] != -1)
                cout << map[i][j] << "  ";
            else
                cout << 'a' << "  ";
        }
        cout <<endl;
    }
}

int solve(){
    queue<pair<int,int>> snake;
    int current_time = 0;
    map[1][1] = 1;
    tail = {1,1};
    snake.push({1,1});

    while(!snake.empty()){
        int x = snake.front().first;
        int y = snake.front().second;
        snake.pop();
        int current_dir = map[x][y];

        pair<int, char> nd = dir_map.front();

        int nx = x + dx[current_dir];
        int ny = y + dy[current_dir];
        current_time++;

        if(is_over(nx,ny) == true){ return current_time;}
        
        int is_apple = map[nx][ny];

        if(nd.first == current_time && nd.second != 0){
            map[nx][ny] = next_dir(current_dir, nd.second);
            dir_map.pop();
        }
        else{
            map[nx][ny] = current_dir;
        }

        snake.push({nx,ny});

        if(is_apple == -1){ //사과가 아니야

        }
        else{
            int x_tail = tail.first;
            int y_tail = tail.second;
            int dir_tail = map[x_tail][y_tail];

            tail = {x_tail+dx[dir_tail], y_tail+dy[dir_tail]};
            map[x_tail][y_tail] = 0;
        }

    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    //파일 입출력, 제출 시 삭제할것
    freopen("input.txt", "r", stdin);

    input();
    cout << solve() <<endl;

    return 0;
}