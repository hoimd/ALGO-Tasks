#include <iostream>
using namespace std;

const int M = 1<<20;
int tab[M];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, mx = 0, t = 0;

    cin >> n >> m;

    while(m--){
        int p;
        cin >> p;

        if(p == n + 1){
            mx = t;
        }else{
            if(tab[p] < mx){
                tab[p] = mx;
            }
            tab[p]++;
            t = max(t,tab[p]);
        }
    }

    for(int i = 1;i <= n;i++){
        cout << (tab[i] > mx ? tab[i] : mx) << ' ';
    }

    return 0;
}


















