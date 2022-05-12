#include<iostream>
#include<vector>
using namespace std;

const int M = 1<<10;
int cost[M];
bool vis[M][M];
vector<int>G[M], path;

void dfs(int v, int mon, int ex){
    path.push_back(v);
    mon -= cost[v];
    vis[v][mon] = true;

    if(v == ex && !mon){
        for(int it : path){
            cout << it << ' ';
        }
        return;
    }

    for(int u : G[v]){
        if(mon >= cost[u] && !vis[u][mon - cost[u]]){
            dfs(u,mon,ex);
        }
    }
    path.pop_back();
}


int main(){
    ios_base::sync_with_stdio(false);
    int n, m, w, k, s;
    cin >> n >> m >> w >> k >> s;

    for(int i = 1;i <= n;i++){
        cin >> cost[i];
    }

    while(m--){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(w,s,k);
    return 0;
}
