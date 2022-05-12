#include<iostream>
#include<vector>
using namespace std;

const int LOGN = 16, M = 1<<LOGN;

vector<int>G[M];
int t = 0, inTime[M], outTime[M], dist[M], P[LOGN][M];
bool vis[M];

void dfs(int prev, int v){
    inTime[v] = ++t;
    vis[v] = true;
    P[0][v] = prev;
    dist[v] = dist[prev] + 1;

    for(int u : G[v]){
       if(!vis[u]){
           dfs(v,u);
       }
   }

    outTime[v] = ++t;
}

bool ancestors(int &v, int &u){
    return inTime[v] <= inTime[u] && outTime[u] <= outTime[v];
}

int lca(int v, int u){
    if(ancestors(v,u)){
        return v;
    }
    if(ancestors(u,v)){
        return u;
    }

    int i = LOGN - 1;

    while(i >= 0){
        if(ancestors(P[i][v],u)){
            i--;
        }else{
            v = P[i][v];
        }
    }
    return P[0][v];
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, res = 0, prev = 1, q;
    cin >> n;

    for(int i = 1;i < n;i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1,1);

    for(int i = 1;i < LOGN;i++){
        for(int j = 1;j <= n;j++){
            P[i][j] = P[i - 1][P[i - 1][j]];
        }
    }

    cin >> q;

    while(q--){
        int next;
        cin >> next;
        int LCA = lca(prev,next);
        res += dist[next] + dist[prev] - 2 * dist[LCA];
        prev = next;
    }

    cout << res;
    return 0;
}
