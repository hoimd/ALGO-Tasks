#include<iostream>
#include<vector>
using namespace std;

const int M = 1<<20;
vector<int>G[M], path;
vector<pair<int,int>>query[M];
int ans[M];

void dfs(int v){
    path.push_back(v);

    if(!query[v].empty()){
        for(auto [nr, dist] : query[v]){
            ans[nr] = path[path.size() - dist - 1];
        }
    }

    for(int u : G[v]){
        dfs(u);
    }

    path.pop_back();
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

    for(int i = 1;i <= q;i++){
        int a, b;
        cin >> a >> b;
        query[a].emplace_back(i,b);
    }

    dfs(1);

    for(int i = 1;i <= q;i++){
        cout << ans[i] << '\n';
    }

    return 0;
}
