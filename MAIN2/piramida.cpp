#include<iostream>
using namespace std;

const int M = 1<<20;
bool tab[M];
int dp[M];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for(int i = 1;i <= n;i++){
        char c;
        cin >> c;
        tab[i] = c - '0';
    }

    dp[1] = 1;

    for(int i = 1;i < n;i++){
        if(tab[i]){
            for(int j = 1;j <= 6;j++){
                if(tab[i + j]){
                    dp[i + j] = (dp[i + j] + dp[i]) % k;
                }
            }
        }
    }

    cout << dp[n];
    return 0;
}
