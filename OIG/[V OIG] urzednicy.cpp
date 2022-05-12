#include<iostream>
#include<vector>
using namespace std;

const int M = 1<<20;
vector<int>G[M], toPair;
bool flag[M];
int res = 0;

void dfs(int v){
    toPair.push_back(v);

    for(int u : G[v]){
        dfs(u);
    }

    if(!flag[v]){
        toPair.pop_back();
        if(!toPair.empty()){
            flag[toPair.back()] = true;
            toPair.pop_back();
            res++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, t;

    cin >> n;
    for(int i = 2;i <= n;i++){
        cin >> t;
        G[t].push_back(i);
    }

    dfs(1);
    cout << res;

    return 0;
}
