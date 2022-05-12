#include<iostream>
#include<vector>
#include<set>
using namespace std;

const int M = 5005, INF = 1e9 + 1;
int price[M], cost1[M], cost2[M];
vector<pair<int,int>>G[M], GT[M];
set<pair<int,int>>q;

void dijkstra(vector<pair<int,int>>Graph[],int dist[]){
    q.emplace(0,1);
    dist[1] = 0;

    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for(auto [u, uCost] : Graph[v]){
            if(dist[u] > dist[v] + uCost){
                dist[u] = dist[v] + uCost;
                q.emplace(dist[u],u);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, res = INF;

    cin >> n;

    for(int i = 1;i <= n;i++){
        cin >> price[i];
        cost1[i] = cost2[i] = INF;
    }

    cin >> m;

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].emplace_back(b,c);
        GT[b].emplace_back(a,c);
    }

    dijkstra(G,cost1);
    dijkstra(GT,cost2);

    for(int i = 1;i <= n;i++){
        res = min(res,cost1[i] + cost2[i] + price[i] / 2);
    }

    cout << res;
    return 0;
}
