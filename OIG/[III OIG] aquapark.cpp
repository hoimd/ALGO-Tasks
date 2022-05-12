#include<iostream>
using namespace std;

const int M = 1<<10;
uint64_t tab[M][M];

int main(){
    ios_base::sync_with_stdio(false);
    int n, r, x, y, z, a, b, c, d;

    cin >> n >> r;
    for(int i = 1;i <= n;i++){
        y = i;
        x = n - i + 1;
        for(int j = 0;j < n;j++){
            cin >> tab[y++][x++];
        }
    }

    for(int i = 1;i <= M;i++){
        for(int j = 1;j <= M;j++){
            tab[i][j] += tab[i][j - 1] + tab[i - 1][j] - tab[i - 1][j - 1];
        }
    }

    while(r--){
        cin >> y >> x >> z;
        a = min(M,y + x - 1 + z);
        b = min(M,n - y + x + z);
        c = max(0,y + x - 2 - z);
        d = max(0,n - y + x - z - 1);
        cout << tab[a][b] - tab[a][d] - tab[c][b] + tab[c][d] << '\n';
    }

    return 0;
}
