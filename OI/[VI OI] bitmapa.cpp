#include<iostream>
#include<queue>
#define x first
#define y second
using namespace std;

const int M = 1<<8;
int dist[M][M];
queue<pair<int,int>>q;

int main(){
    ios_base::sync_with_stdio(false);
    const pair<int,int> vectors[] = {{-1,0},{1,0},{0,-1},{0,1}};
    int n, m;

    cin >> n >> m;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            dist[i][j] = 1e9 + 1;
            char c;
            cin >> c;
            if(c - '0' == 1){
                dist[i][j] = 0;
                q.emplace(j,i);
            }
        }
    }

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(auto [dx, dy] : vectors){
            if(dist[y][x] + 1 < dist[y + dy][x + dx]){
                dist[y + dy][x + dx] = dist[y][x] + 1;
                q.emplace(x + dx,y + dy);
            }
        }
    }

    for(int i = 1;i <= n;i++){
        for (int j = 1; j <= m; j++){
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}


















