#include<iostream>
#include<vector>
#define x first
#define y second
using namespace std;

const int M = 1<<10;
int poolSize[M*M], considered[M*M], pool[M][M];
pair<int,int>upperLeft[M*M];
vector<pair<int,int>>v;

int main(){
    ios_base::sync_with_stdio(false);
    int n, res = 0, poolCount = 0;
    const pair<int,int> st[] = {{-1,0},{1,0},{0,-1},{0,1}},
            hor[] = {{-1,0},{0,-1},{1,-1},{2,0},{1,1},{0,1}},
            ver[] = {{0,-1},{1,0},{1,1},{0,2},{-1,-1},{-1,0}};

    cin >> n;
    for(int i = 2;i < n + 2;i++){
        for(int j = 2;j < n + 2;j++){
            char c;
            cin >> c;
            if(c == 'B'){
                int t = max(pool[i - 1][j], pool[i][j - 1]);
                if (t != 0){
                    pool[i][j] = t;
                    poolSize[t]++;
                }else{
                    poolCount++;
                    upperLeft[poolCount] = make_pair(j - 1, i - 1);
                    pool[i][j] = poolCount;
                    poolSize[poolCount]++;
                }
            }
        }
    }

    if(poolSize[1] == n*n){
        cout << n*n;
        return 0;
    }

    for(int i = 2;i < n + 2;i++){
        for(int j = 2;j < n + 1;j++){
            if(!pool[i][j] && !pool[i][j + 1]){
                int s = 0;
                for(auto [dx, dy] : hor){
                    int p = pool[i + dy][j + dx];
                    s += poolSize[p] * !considered[p];
                    considered[p]++;
                }

                res = max(res,s + 2);

                for(auto [dx, dy] : hor){
                    int p = pool[i + dy][j + dx];
                    considered[p]--;
                }
            }
        }
    }

    for(int i = 2;i < n + 1;i++){
        for(int j = 2;j < n + 2;j++){
            if(!pool[i][j] && !pool[i + 1][j]){
                int s = 0;
                for(auto [dx, dy] : ver){
                    int p = pool[i + dy][j + dx];
                    s += poolSize[p] * !considered[p];
                    considered[p]++;
                }

                res = max(res,s + 2);

                for(auto [dx, dy] : ver){
                    int p = pool[i + dy][j + dx];
                    considered[p]--;
                }
            }
        }
    }

    for(int i = 1;i <= poolCount;i++){
        pair<int,int>best;
        int width = 0, height = 0, best1 = 0, best2 = 0;
        int x = upperLeft[i].x, y = upperLeft[i].y + 1;

        while(pool[y][x + 1]){
            height++;
            v.emplace_back(x,y);
            y++;
        }

        x = upperLeft[i].x + 1;
        y = upperLeft[i].y;

        while(pool[y + 1][x]){
            width++;
            v.emplace_back(x,y);
            x++;
        }

        x = upperLeft[i].x + width + 1;
        y = upperLeft[i].y + height;

        while(pool[y][x - 1]){
            v.emplace_back(x,y);
            y--;
        }

        x = upperLeft[i].x + width;
        y = upperLeft[i].y + height + 1;

        while(pool[y - 1][x]){
            v.emplace_back(x,y);
            x--;
        }

        for(auto [x, y] : v){
            int s = 0;
            for(auto [dx, dy] : st){
                int p = pool[y + dy][x + dx];
                s += poolSize[p];
            }
            if(s + 1 > best1){
                best1 = s + 1;
                best = make_pair(x,y);
            }
        }

        for(auto [dx, dy] : st){
            int p = pool[best.y + dy][best.x + dx];
            considered[p]++;
        }

        for(auto [x, y] : v){
            int s = 0;
            for(auto [dx, dy] : st){
                int p = pool[y + dy][x + dx];
                s += poolSize[p] * !considered[p];
                considered[p]++;
            }

            best2 = max(s + 1,best2);

            for(auto [dx, dy] : st){
                int p = pool[y + dy][x + dx];
                considered[p]--;
            }
        }

        for(auto [dx, dy] : st){
            int p = pool[best.y + dy][best.x + dx];
            considered[p]--;
        }

        res = max(res,best1 + best2);
        v.clear();
    }

    cout << res;
    return 0;
}
