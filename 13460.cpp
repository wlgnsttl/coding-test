#include <iostream>
#include <queue>
  
using namespace std;

int N, M;
char map[11][11] = {0,};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
pair<int,int> rpos , bpos, gpos;

struct rbpos
{
    int numb;
    pair<int,int> redpos;
    pair<int,int> bluepos;
    rbpos() : numb(0), redpos({0, 0}), bluepos({0, 0}) {}
    rbpos(int n, pair<int, int> r, pair<int, int> b) : numb(n), redpos(r), bluepos(b) {}
};

struct compare
{
    bool operator()(const rbpos& a, const rbpos& b){
        return a.numb > b.numb;
    }
};

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char temp;
            cin >> temp;
            if(temp == 'R'){rpos.first=i; rpos.second=j; map[i][j]='.';}
            else if(temp == 'B'){bpos.first=i; bpos.second=j; map[i][j]='.';}
            else if(temp == 'O'){gpos.first=i; gpos.second=j; map[i][j]='O';}
            else{map[i][j]=temp;}
        }   
    }
}

bool __move_balls(rbpos& cp, const int& dir){    //두 공을 지정방향으로 한칸씩만 이동

    pair<int,int> nr, nb;
    nr.first = cp.redpos.first + dx[dir];
    nr.second = cp.redpos.second + dy[dir];
    nb.first = cp.bluepos.first + dx[dir];
    nb.second = cp.bluepos.second + dy[dir];

    if(map[nr.first][nr.second] == '#' || cp.redpos == gpos){
        nr = cp.redpos;
    }
    if(map[nb.first][nb.second] == '#' || cp.bluepos == gpos){
        nb = cp.bluepos;
    }

    if(nr==nb && (nr != gpos)){
        return false;
    }

    if(cp.redpos == nr && cp.bluepos == nb){
        return false;
    }

    cp.redpos = nr;
    cp.bluepos = nb;

    if(nr == gpos && nb == gpos){
        return false;
    }
    
    return true;
}

rbpos move_balls(const rbpos& cp, const int& dir){
    bool moving = true;
    rbpos next = cp;
    while(moving){
        if(!__move_balls(next, dir)){
            moving = false;
        }
    }

    if(cp.redpos != next.redpos || cp.bluepos != next.bluepos){
        next.numb++;
    }
    return next;
}

int solve(){
    priority_queue<rbpos, vector<rbpos>, compare> q;
    q.push(rbpos(0,rpos,bpos));

    while(!q.empty()){
        rbpos current = q.top();
        q.pop();

        if(current.numb >= 10){
            break;
        }

        for(int i=0; i<4; i++){
            rbpos next = move_balls(current, i);

            if(next.numb == current.numb){  //두 공의 위치가 변함이 없었을 경우
                continue;
            }
            else{   //뭔가 공의 변화가 있긴할때
                if(next.redpos == gpos && next.bluepos != gpos){        //빨간공이 목표에 먼저 도착했을때
                    return next.numb;
                }
                else if(next.redpos != gpos && next.bluepos == gpos){   //파란공이 목표에 먼저 도착했을때
                    continue;
                }
                else if(next.redpos == gpos && next.bluepos == gpos){   //동시에 목표에 도착했을때
                    continue;
                }
                else{   //둘다 아직 도착 못했으면
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    freopen("input.txt", "r", stdin);   //제출 시 삭제

    input();
    cout << solve() << '\n';

    return 0;
}