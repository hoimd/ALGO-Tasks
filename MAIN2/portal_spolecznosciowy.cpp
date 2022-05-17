#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int M = 1<<18;
bool vis[M];
int dist[M];
vector<int>G[M];
vector<pair<int,int>>friends;
queue<int>q;

void bfs(int &k){
    vis[k] = true;
    q.push(k);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : G[v]){
            if(!vis[u]){
                vis[u] = true;
                dist[u] = dist[v] + 1;
                friends.emplace_back(u,dist[u]);
                q.push(u);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int z;
    cin >> z;

    while(z--){
        int n, m, k;
        cin >> n >> m;
        while(m--){
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        cin >> k;

        bfs(k);
        sort(friends.begin(),friends.end());

        cout << "Znajomi numeru " << k << ":\n";

        for(auto it : friends){
            cout << it.first << ": " << it.second << '\n';
        }

        int groups = 1;

        for(int i = 1;i <= n;i++){
            if(!vis[i]){
                bfs(i);
                groups++;
            }
        }

        cout << "Grup znajomych jest " << groups << ".\n";

        for(int i = 1;i <= n;i++){
            vis[i] = dist[i] = 0;
            G[i].clear();
        }

        friends.clear();
    }
    
    return 0;
}
