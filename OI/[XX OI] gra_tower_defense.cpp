#include<iostream>
#include<vector>
using namespace std;

const int M = 1<<20;
bool vis[M];
vector<int>G[M], v;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, t;

    cin >> n >> m >> t;

    while(m--){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            vis[i] = true;
            v.push_back(i);
            for(int j : G[i]){
                vis[j] = true;
                for(int k : G[j]){
                    vis[k] = true;
                }
            }
        }
    }

    cout << v.size() << endl;
    for(int i : v){
        cout << i << ' ';
    }

    return 0;
}
