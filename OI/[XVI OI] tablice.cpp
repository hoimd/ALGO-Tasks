#include<iostream>
using namespace std;

const int M = 1<<10, MM = 2e6 + 1, shift = 1e6;
int tab[M][M], tab1[M][M], whichRow[MM], whichCol[MM];
bool flag[MM];

bool solve(){
    for(int i = 0;i < MM;i++){
        flag[i] = whichRow[i] = whichCol[i] = 0;
    }

    int n, m;
    cin >> n >> m;

    for(int i = 1;i <= n;i++){
        int minr = MM;
        for(int j = 1;j <= m;j++){
            cin >> tab[i][j];
            tab[i][j] += shift;
            minr = min(minr, tab[i][j]);
        }
        whichRow[minr] = i;
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> tab1[i][j];
            tab1[i][j] += shift;
        }
    }

    for(int j = 1;j <= m;j++){
        int minc = MM;
        for(int i = 1;i <= n;i++){
            minc = min(tab[i][j], minc);
        }
        whichCol[minc] = j;
    }

    for(int i = 1;i <= n;i++){
        int min1 = MM;
        for(int j = 1;j <= m;j++){
            min1 = min(min1, tab1[i][j]);
        }

        int r = whichRow[min1];

        for(int j = 1;j <= m;j++){
            flag[tab[r][j]] = true;
        }

        for(int j = 1;j <= m;j++){
            if(flag[tab1[i][j]]){
                flag[tab1[i][j]] = false;
            }else{
                return false;
            }
        }
    }

    for(int j = 1;j <= m;j++){
        int min1 = MM;
        for(int i = 1; i <= n; i++){
            min1 = min(min1, tab1[i][j]);
        }

        int c = whichCol[min1];

        for(int i = 1; i <= n; i++){
            flag[tab[i][c]] = true;
        }

        for(int i = 1; i <= n; i++){
            if(!flag[tab1[i][j]]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while(t--){
        cout << (solve() ? "TAK\n" : "NIE\n");
    }
    return 0;
}
