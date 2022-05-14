#include<iostream>
using namespace std;

const int LOGN = 20, M = 1<<LOGN;
int P[LOGN][M];

int solve(int v, int d){
    int i = LOGN - 1;

    while(i >= 0){
        if(d - (1 << i) <= 0){
            i--;
        }else{
            v = P[i][v];
            d -= 1 << i;
        }
    }
    return P[0][v];
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    for(int i = 2;i <= n;i++){
        cin >> P[0][i];
    }

    P[0][1] = 1;

    for(int i = 1;i < LOGN;i++){
        for(int j = 1;j <= n;j++){
            P[i][j] = P[i - 1][P[i - 1][j]];
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        cout << solve(a,b) << '\n';
    }

    return 0;
}
