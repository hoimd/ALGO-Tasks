#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

const in M = 1<<20;
uint64_t tab[M];
multiset<pair<uint64_t,int>>Q;

int main(){
    ios_base::sync_with_stdio(false);
    int n, k;

    cin >> n >> k;

    for(int i = 1;i <= n;i++){
        cin >> tab[i];
    }

    if(k == 1){
        cout << 0;
        return 0;
    }

    sort(tab + 1,tab + n + 1);
    Q.emplace(tab[1],1);

    for(int i = 1;i < k - 1;i++){
        auto [value, nr] = *Q.begin();
        Q.erase(Q.begin());
        if(nr < n){
            Q.emplace(value + tab[nr + 1],nr + 1);
            Q.emplace(value + tab[nr + 1] - tab[nr],nr + 1);
        }
    }

    cout << Q.begin()->first;
    return 0;
}
