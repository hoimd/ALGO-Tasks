#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 1<<20;
vector<int>G[M];
vector<pair<int,int>>layer[M];
int dist[M], inTime[M], tm = 0;

void dfs(int v,int depth){
    inTime[v] = ++tm;
    layer[depth].emplace_back(tm,v);
    dist[v] = depth;

    for(int u : G[v]){
        dfs(u, depth + 1);
    }

    tm++;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    for(int i = 2;i <= n;i++){
        int t;
        cin >> t;
        G[t].push_back(i);
    }

    dfs(1,0);

    while(q--){
        int a, b;
        cin >> a >> b;
        int s = dist[a] - b;
        auto it = upper_bound(layer[s].begin(), layer[s].end(), make_pair(inTime[a], 0)) - 1;
        cout << it->second << '\n';
    }

    return 0;
}
