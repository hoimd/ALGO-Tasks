#include<iostream>
using namespace std;

const int M = 1<<20;
int tab[M], rep[M];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    uint64_t res = 0;
    cin >> n >> m;

    for(int l = 1, r = 1; r <= n; r++){
        cin >> tab[r];
        rep[tab[r]]++;

        while(rep[tab[r]] > 1){
            rep[tab[l]]--;
            l++;
        }

        res += r - l + 1;
    }

    cout << res;
    return 0;
}
