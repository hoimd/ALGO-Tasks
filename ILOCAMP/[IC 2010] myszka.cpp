#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int M = 1<<20, INF = 2e9 + 1;
int cheese[M], width[M], s, d;
vector<pair<int,int>>G[M];
vector<int>toClear;
queue<int>q;

bool check(int &startWidth){
    for(int it : toClear){
        width[it] = INF;
    }
    toClear.clear();

    while(!q.empty()){
        q.pop();
    }

    q.push(s);
    width[s] = cheese[s] + startWidth;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto [u, uWidth] : G[v]){
            if(uWidth >= width[v] && width[u] > width[v] + cheese[u]){
                if(u == d){
                    return true;
                }
                width[u] = width[v] + cheese[u];
                toClear.push_back(u);
                q.push(u);
            }
        }
    }
    return false;
}

int binsearch(int l, int r){
    while(l < r){
        int mid = (l + r + 1) / 2;

        if(check(mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }

    return check(r) ? r : -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, maxEdge = 0;
    cin >> n >> m >> s >> d;

    for(int i = 1;i <= n;i++){
        cin >> cheese[i];
        width[i] = INF;
    }

    for(int i = 1;i <= m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].emplace_back(b,c);
        G[b].emplace_back(a,c);
        maxEdge = max(maxEdge, c);
    }

    cout << binsearch(1, maxEdge - cheese[s]);
    return 0;
}
