#include <iostream>
#include <queue>
#include <vector>
#define MAX 20001
#define INF 987654321

using namespace std;

int V, E, K;//정점의 개수, 간선의 개수, 시작정점의 번호
vector<pair<int,int>> path[MAX];
int min_path[MAX];//최단거리 테이블

/*
알고리즘에 필요한 input 데이터를 path vector에 입력하는 함수
*/
void input_path(){
    std::cin >> V >> E;
    std::cin >> K;

    for(int i=0; i<MAX; i++) min_path[i] = INF;
    min_path[K] = 0;

    for(int i=0; i<E; i++){
        int u, v, w;
        std::cin >> u >> v >> w;
        path[u].push_back({v,w});
    }

}

/*
path에 입력된 값으로 min_path를 업데이트 하는 함수
*/
void solve(){
    /*
    우선순위 큐를 이용한 다익스트라 알고리즘으로 시간복잡도가 Elog(V)이다
    배열을 이용한 다익스트라보다 노드의 개수가 많을때 효과적이다
    */
    priority_queue<pair<int,int>> pq;// cost, node

    pq.push({0,K});
    min_path[K] = 0;

    while(!pq.empty()){
        int cur_cost = -pq.top().first;//top에 가장 큰 값이 올라오므로 음수로 바꿔서 가장 작은 값이 올라오게 만든다
        int cur_node = pq.top().second;
        pq.pop();

        for(int i=0; i<path[cur_node].size(); i++){
            pair<int,int> next = path[cur_node][i];//node, cost
            if(min_path[next.first] > cur_cost + next.second){//min_path에 저장된 값보다 cost가 작으면 실행한다
                pq.push({-(cur_cost+next.second), next.first});
                min_path[next.first] = cur_cost + next.second;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	std::cin.tie(0);

    //파일 입출력, 제출시 삭제할것
    freopen("input.txt", "r", stdin);
    
    //in
    input_path();

    //solve
    solve();

    //out
    for(int i=1; i<=V; i++){
        int temp = min_path[i];
        if(temp == INF){
            std::cout << "INF" << '\n';
        }
        else{
            std::cout << temp << '\n';
        }
    }

    return 0;
}