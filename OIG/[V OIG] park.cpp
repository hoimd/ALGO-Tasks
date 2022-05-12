#include<iostream>
using namespace std;

const int M = 1<<20;
int tab[M], pref[M], suf[M];

int main(){
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;

    pref[0] = suf[n + 1] = 0;

    for(int i = 1;i <= n;i++){
        cin >> tab[i];
        if(tab[i] > pref[i - 1]){
            pref[i] = tab[i];
        }else{
            pref[i] = pref[i - 1];
        }
    }

    for(int i = n;i > 0;i--){
        if(tab[i] > suf[i + 1]){
            suf[i] = tab[i];
        }else{
            suf[i] = suf[i + 1];
        }
    }

    for(int i = 1;i <= n;i++){
        cout << pref[i] << ' ' << suf[i] << '\n';
    }

    return 0;
}
