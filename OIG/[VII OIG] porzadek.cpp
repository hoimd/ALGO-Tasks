#include<iostream>
using namespace std;

const int M = 1<<20;
uint64_t rud[M], nast[M], par[M];

int main(){
    ios_base::sync_with_stdio(false);
    int n, q;
    
    cin >> n;

    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;

        nast[i] = nast[i - 1];
        rud[i] = rud[i - 1];
        par[i] = par[i - 1];

        if(c == 'N'){
            nast[i]++;
            par[i] += rud[i];
        }
        else{
            rud[i]++;
        }
    }
    
    cin >> q;

    while(q--){
        int p, k;
        cin >> p >> k;
        cout << par[k] - par[p - 1] - ((nast[k] - nast[p - 1]) * rud[p - 1]) << '\n';
    }

    return 0;
}
