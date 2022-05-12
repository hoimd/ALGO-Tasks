#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int M = 1<<18;
int guild[M];
vector<int>G[M];
queue<int>q;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = 1;i <= n;i++){
        if(!guild[i]){
            if(G[i].empty()){
                cout << "NIE";
                return 0;
            }

            q.push(i);
            guild[i] = 1;

            while(!q.empty()){
                int v = q.front();
                q.pop();
                for(int u : G[v]){
                    if(!guild[u]){
                        guild[u] = 1 + guild[v] % 2;
                        q.push(u);
                    }
                }
            }
        }
    }

    cout << "TAK\n";
    for(int i = 1;i <= n;i++){
        cout << (guild[i] == 1 ? "K\n" : "S\n");
    }

    return 0;
}
