#include<iostream>
using namespace std;

const int M = 1<<20;
int tab[M];

int main(){
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;

        uint64_t sum = 0;
        int max1 = 0, max2 = 0, pos;

        for (int i = 1; i <= n; i++){
            cin >> tab[i];
            sum += tab[i];

            if (tab[i] >= max1){
                pos = i;
                max2 = max1;
                max1 = tab[i];
            }
        }

        bool print = false;
        max1 *= 2;
        max2 *= 2;

        for (int i = 1; i <= n; i++){
            if((sum - tab[i]) % 2 == 0 && sum - tab[i] >= (i == pos ? max2 : max1)){
                print = true;
                cout << i << ' ';
            }
        }

        cout << (print ? "\n" : "NIE\n");
    }

    return 0;
}
