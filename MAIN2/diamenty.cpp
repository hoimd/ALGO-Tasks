#include<iostream>
using namespace std;

const int M = 1<<10;
int dp[M][M];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while(q--) {
        int n, m;
        cin >> m >> n;

        for(int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                int t;
                cin >> t;
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + t;
            }
        }

        cout << dp[n][m] << '\n';

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = 0;
            }
        }
    }

    return 0;
}
