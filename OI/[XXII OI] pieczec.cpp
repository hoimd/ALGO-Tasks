#include<cstdio>
#include<vector>
#define x first
#define y second
using namespace std;

const int M = 1<<10;
char tab[M][M];

bool solve(){
    int n, m, a, b;
    pair<int,int>prev;
    vector<pair<int,int>>v;

    scanf("%i %i %i %i\n",&n, &m, &a, &b);

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            tab[i][j] = getchar();
        }
        getchar();
    }

    for(int i = 1;i <= a;i++){
        for(int j = 1;j <= b;j++){
            if (getchar() == 'x'){
                v.emplace_back(j - prev.x,i - prev.y);
                prev = make_pair(j,i);
            }
        }
        getchar();
    }

    v.front().x = v.front().y = 0;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(tab[i][j] == 'x'){
                int x = j, y = i;
                for(auto [dx, dy] : v){
                    x += dx;
                    y += dy;
                    if(x < 1 || x > m || y < 1 || y > n || tab[y][x] != 'x'){
                        return false;
                    }
                    tab[y][x] = 0;
                }
            }
        }
    }
    return true;
}

int main(){
    int q;
    scanf("%i\n",&q);

    while(q--){
        printf(solve() ? "TAK\n" : "NIE\n");
    }

    return 0;
}
