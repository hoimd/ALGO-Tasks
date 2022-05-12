#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,bool>>v;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    uint64_t res = 0, ver = 1, hor = 1;

    cin >> n >> m;

    for(int i = 1;i < n;i++){
        int t;
        cin >> t;
        v.emplace_back(t,true);
    }

    for(int j = 1;j < m;j++){
        int t;
        cin >> t;
        v.emplace_back(t,false);
    }

    sort(v.begin(),v.end(),[](auto &a, auto &b){return a.first > b.first;});

    for(auto [cost, isVert] : v){
        if(isVert){
            res += cost * hor;
            ver++;
        }else{
            res += cost * ver;
            hor++;
        }
    }

    cout << res;
    return 0;
}


















