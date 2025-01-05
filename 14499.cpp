#include <iostream>
  
using namespace std;

int N, M, X, Y, K;
int map[21][21] = {0,};

const int dx[5] = {-999, 0, 0, -1, 1};
const int dy[5] = {-999, 1, -1, 0, 0};

int dice[6] = {0,}; //밑, 위, 북, 동, 남, 서

void input_map(){
    cin >> N >> M >> X >> Y >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
}

bool can_go(int cmd){
    int nx = X + dx[cmd];
    int ny = Y + dy[cmd];

    if(nx<0 || ny <0 || nx > N-1 || ny > M-1){
        return false;
    }
    else{
        return true;
    }
}

void roll(int cmd){
    int temp[6];    //밑0, 위1, 북2, 동3, 남4, 서5
    for (int i = 0; i < 6; i++) {
        temp[i] = dice[i];
    }

    //동
    if(cmd == 1){//밑0->서5, 서5->위1, 위1->동3, 동3->밑0
        dice[5] = temp[0];
        dice[1] = temp[5];
        dice[3] = temp[1];
        dice[0] = temp[3];
    }
    
    //서
    else if (cmd == 2){//밑->동3, 서->밑0, 위->5서, 동->위1
        dice[3] = temp[0];
        dice[0] = temp[5];
        dice[5] = temp[1];
        dice[1] = temp[3];
    }

    //북
    else if (cmd == 3){//밑0->남4, 남4->위1, 위1->북2, 북2->밑0
        dice[4] = temp[0];
        dice[1] = temp[4];
        dice[2] = temp[1];
        dice[0] = temp[2];
    }

    //남
    else if (cmd == 4){//밑->북2, 남->밑0, 위->남4, 북->위1
        dice[2] = temp[0];
        dice[0] = temp[4];
        dice[4] = temp[1];
        dice[1] = temp[2];
    }
}

void update(){
    if(map[X][Y] == 0){
        map[X][Y] = dice[0];
    }
    else{
        dice[0] = map[X][Y];
        map[X][Y] = 0;
    }
}

void solve(int cmd){
    if(can_go(cmd) == false){ return;} //이동 가능한지 판단

    X += dx[cmd];
    Y += dy[cmd];

    roll(cmd);
    update();
    cout << dice[1] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    freopen("input.txt", "r", stdin);   //제출 시 삭제

    input_map();

    while(K--){
        int command = 0;
        cin >> command;

        solve(command);
    }

    return 0;
}