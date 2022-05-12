#include<iostream>
#include<vector>
using namespace std;

const int M = 1<<20;
int tab[M];
vector<pair<uint64_t,uint64_t>>v;

int main() {
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;

    for(int i = 0;i < n;i++){
        cin >> tab[i];
    }

    int mx = 1e9 + 1;

    for(int i = n - 1;i >= 0;i--){
        if(tab[i] < mx){
            v.emplace_back(i + 1,tab[i]);
            mx = tab[i];
        }
    }

    uint64_t oldPos = 0, res = 0;

    for(auto it = v.rbegin();it != v.rend();it++){
        auto [pos, cost] = *it;
        res += (pos - oldPos) * cost;
        oldPos = pos;
    }

    cout << res;
    return 0;
}


















