#include<iostream>
using namespace std;

const int M = 1<<21;
uint64_t tab[M];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 2;i < M;i++){
        tab[i] = 1;
    }

    for(int i = 2;i < M;i++){
        if(tab[i]){
            for(int j = 2 * i;j < M; j += i){
                tab[j] = 0;
            }
        }
        tab[i] = tab[i - 1] + i * tab[i];
    }

    int q;
    cin >> q;

    while(q--){
        int a, b;
        cin >> a >> b;
        cout << tab[b] - tab[a - 1] << '\n';
    }

    return 0;
}
