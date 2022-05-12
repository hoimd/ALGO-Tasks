#include<iostream>
using namespace std;

const int M = 1<<20;
int tab[M], pref[M], suf[M];

int main(){
    ios_base::sync_with_stdio(false);
    int n, res = 0;
    tab[0] = tab[n + 1] = 1e9 + 1;

    cin >> n;

    for(int i = 1;i <= n;i++){
        cin >> tab[i];
    }

    for(int i = 1;i <= n;i++){
        if(tab[i] >= tab[i - 1]){
            pref[i] = pref[i - 1] + 1;
        }
    }

    for(int i = n;i > 0;i--){
        if(tab[i] >= tab[i + 1]){
            suf[i] = suf[i + 1] + 1;
        }
    }

    for(int i = 1;i <= n;i++){
        res = max(res,suf[i] + pref[i] + 1);
    }

    cout << res;
    return 0;
}
