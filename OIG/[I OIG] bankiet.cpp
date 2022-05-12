#include <iostream>
using namespace std;

const int M = 1<<20;
int tab[M];

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 1;i <= n;i++){
        cin >> tab[i];
    }

    int res = 0;
    for(int i = 1;i <= n;i++){
        if(tab[i]){
            res++;
            int t = i;
            while(tab[t]){
                int t2 = t;
                t = tab[t];
                tab[t2] = 0;
            }
        }
    }

    cout << res;
    return 0;
}


















