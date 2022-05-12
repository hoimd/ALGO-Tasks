#include<iostream>
using namespace std;

const int M = 1<<20;
int tab[M], pref[M], suf[M];

int main(){
    ios_base::sync_with_stdio(false);

    int n, res = 1e9 + 1;
    cin >> n;

    for(int i = 1;i <= n;i++){
        cin >> tab[i];
        pref[i] = !tab[i] + pref[i - 1];
    }

    for(int i = n;i > 0;i--){
        suf[i] = tab[i] + suf[i + 1];
    }

    for(int i = 0;i <= n;i++) {
        res = min(res,pref[i] + suf[i + 1]);
    }

    cout << res;
    return 0;
}
