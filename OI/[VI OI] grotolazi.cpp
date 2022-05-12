#include<iostream>
#include<queue>
using namespace std;

const int INF = 1e9 + 1, M = 205;
queue<int>q;
vector<int>G[M];
vector<int>::iterator begins[M];
int flow[M][M], dist[M], n;

bool bfs(){
    for(int i = 2;i <= n;i++){
        dist[i] = 0;
    }
    dist[1] = 1;
    q.push(1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : G[v]){
            if(!dist[u] && flow[v][u] > 0){
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    return dist[n];
}

int dfs(int v, int minimum){
    int res = 0;
    if(v == n || minimum == 0){
        return minimum;
    }
    for(auto it = begins[v];it != G[v].end();it++){
        int u = *it;
        if(dist[v] + 1 == dist[u] && flow[v][u] > 0){
            int y = dfs(u,min(minimum,flow[v][u]));
            flow[v][u] -= y;
            flow[u][v] += y;
            minimum -= y;
            res += y;
            if(minimum == 0){
                break;
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    int x, v, res = 0;
    cin >> n;

    for(int i = 1;i < n;i++){
        cin >> x;
        while(x--){
            cin >> v;
            G[i].push_back(v);
            G[v].push_back(i);
            flow[i][v] = INF;
            if(v == n){
                flow[i][v] = 1;
            }
        }
    }

    for(int i : G[1]){
        flow[1][i] = 1;
    }

    while(bfs()){
        for (int i = 1;i <= n;++i){
            begins[i] = G[i].begin();
        }
        res += dfs(1,INF);
    }

    cout << res;
    return 0;
}
