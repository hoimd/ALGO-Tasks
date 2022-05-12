#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 10005;
vector<int>G[M], GT[M];
vector<pair<int,int>>v;
int t = 0, outTime[M], scc[M];
bool vis[M], edgeIn[M], edgeOut[M];

void dfs_visit(int v){
    t++;
    vis[v] = true;
    for(int u : G[v]){
       if(!vis[u]){
           dfs_visit(u);
       }
   }
    outTime[v] = ++t;
}

void scc_dfs(int v,int num){
    scc[v] = num;
    for(int u : GT[v]){
        if(!scc[u]){
            scc_dfs(u,num);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int m, n;
    cin >> n >> m;

    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        GT[b].push_back(a);
    }

    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            dfs_visit(i);
        }
        v.emplace_back(-outTime[i],i);
    }

    sort(v.begin(),v.end());

    int sccCount = 0;

    for(auto [time, vert] : v){
        if(!scc[vert]){
            sccCount++;
            scc_dfs(vert,sccCount);
        }
    }

    if(sccCount == 1){
        cout << 0;
        return 0;
    }

    for(int i = 1;i <= n;i++){
        for(int j : G[i]){
            if(scc[i] != scc[j]){
                edgeOut[scc[i]] = true;
                edgeIn[scc[j]] = true;
            }
        }
    }

    int v_in = 0, v_out = 0;

    for(int i = 1;i <= sccCount;i++){
        v_in += edgeIn[i];
        v_out += edgeOut[i];
    }

    cout << max(sccCount - v_in, sccCount - v_out);
    return 0;
}
