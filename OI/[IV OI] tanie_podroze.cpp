#include<iostream>
#include<vector>
#include<tuple>
#include<set>
using namespace std;

const int M = 1<<10, INF = 1e9 + 1;

set<pair<int,int>>q;
vector<int>G[M], cost(M), one(M,1);
int dist[M], dist2[M], distances[M], hot[M];
pair<int,int>tab[M][M];
tuple<int,int,int>best;
int d, h;

void in(){
    cin >> d >> h;

    for(int i = 1;i <= h;i++){
        cin >> distances[i] >> cost[i];
    }

    for(int i = 0;i < h;i++){
        for(int j = i + 1;j <= h && distances[j] - distances[i] <= 800;j++){
            G[i].push_back(j);
        }
    }
}

void dijkstra(vector<int> &weight, vector<int> &weight2){
    for(int i = 1;i <= h;i++){
        dist[i] = dist2[i] = INF;
    }

    best = make_tuple(INF, INF, 0);
    q.emplace(0,0);

    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());

        if(distances[v] >= d - 800){
            best = min(best,make_tuple(dist[v], dist2[v], v));
        }

        for(int u : G[v]){
            int t = dist[v] + weight[u];
            if(dist[u] > t || (dist[u] == t && dist2[u] > dist2[v] + weight2[u])){
                dist[u] = t;
                dist2[u] = dist2[v] + weight2[u];
                hot[u] = hot[v] + 1;
                tab[u][hot[u]] = make_pair(v, hot[v]);
                q.emplace(t,u);
            }
        }
    }
}

void print_path(bool mode){
    vector<int>path;
    int v = get<2>(best);
    int c = mode ? get<1>(best) : get<0>(best);

    while(v != 0){
        path.push_back(v);
        tie(v,c) = tab[v][c];
    }

    for(auto it = path.rbegin();it != v.rend();it++){
        cout << distances[*it] << ' ';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);

    in();

    dijkstra(cost,one);
    print_path(true);

    dijkstra(one,cost);
    print_path(false);

    return 0;
}
