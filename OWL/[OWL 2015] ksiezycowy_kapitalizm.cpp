#include<iostream>
using namespace std;

const int M = 1<<20;
int tab[M];

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    u_int64_t res = 0;

    cin >> n;
    tab[n] = -1;

    for(int i = 0;i < n;i++){
        cin >> tab[i];
    }

    for(int i = 0;i < n;i++){
        if(tab[i] < tab[i + 1]){
            res += tab[i + 1] - tab[i];
        }
    }

    cout << res;
    return 0;
}
