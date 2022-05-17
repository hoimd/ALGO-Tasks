#include<cstdio>
#include<vector>
#define x first
#define y second
using namespace std;

const int M = 105;
char tab[M][M];
bool flag[M][M];
vector<pair<int,int>>v[20], toMark;

int main(){
    int n, m, a, b, p, cnt = 0;
    scanf("%i %i\n",&n,&m);

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            tab[i][j] = getchar();
            if(tab[i][j] == '#'){
                flag[i][j] = true;
                cnt++;
            }
        }
        getchar();
    }

    scanf("%i\n",&p);

    for(int t = 0;t < p;t++){
        int px = 0, py = 0;
        scanf("%i %i\n",&a,&b);
        for(int i = 1; i <= a; i++){
            for (int j = 1; j <= b; j++){
                if(getchar() == '#') {
                    v[t].emplace_back(j - px,i - py);
                    px = j;
                    py = i;
                }
            }
            getchar();
        }
        v[t].front().x = v[t].front().y = 0;
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(tab[i][j] == '#'){
                for(int t = 0;t < p;t++){
                    bool iff = true;
                    int x = j, y = i;

                    for(auto [dx, dy] : v[t]){
                        x += dx;
                        y += dy;
                        if(x < 1 || x > m || y < 1 || y > n || tab[y][x] != '#'){
                            iff = false;
                            break;
                        }
                        toMark.emplace_back(x,y);
                    }

                    if(iff == true){
                        for(auto [x, y] : toMark){
                             cnt -= flag[y][x];
                             flag[y][x] = false;
                        }
                    }
                    toMark.clear();
                }
            }
        }
    }

    printf(cnt > 0 ? "NIE" : "TAK");
    return 0;
}
