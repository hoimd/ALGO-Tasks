#include<iostream>
#include<queue>
using namespace std;

const int M = 1<<10;
int dist[M][M];
queue<pair<int,int>>q;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, res = M;

    cin >> n >> m;

    for(int i = 1;i <= n;i++){
        int flag = 0, temp;
        for(int j = 1;j <= m;j++){
            dist[i][j] = M;
            cin >> temp;
            flag += temp;

            if(temp){
                dist[i][j] = 0;
            }

            if(!flag){
                dist[i][j] = 0;
                q.emplace(j,i);
            }
        }
    }

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if(x == m){
            res = min(res,dist[y][x]);
        }

        if(dist[y][x] + 1 < dist[y + 1][x]){
            dist[y + 1][x] = dist[y][x] + 1;
            q.emplace(x,y + 1);
        }

        if(dist[y][x] + 1 < dist[y - 1][x]){
            dist[y - 1][x] = dist[y][x] + 1;
            q.emplace(x,y - 1);
        }

        if(dist[y][x] < dist[y][x + 1]){
            dist[y][x + 1] = dist[y][x];
            q.emplace(x + 1,y);
        }
    }

    if(res == M){
        cout << "NIE";
    }else{
        cout << res;
    }

    return 0;
}
