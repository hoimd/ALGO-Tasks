#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>>v;

int main(){
    ios_base::sync_with_stdio(false);
    int n, prev, cnt;
    cin >> n;

    for(int i = 1;i <= n;i++){
        int t;
        cin >> t;
        if(t != prev){
            v.emplace_back(prev,cnt);
            prev = t;
            cnt = 1;
        }else{
            cnt++;
        }
    }

    v.emplace_back(prev,cnt);

    cin >> n;

    while(n--){
        int t;
        cin >> t;
        auto [num, rpt] = *lower_bound(v.begin() + 1, v.end(),make_pair(t,0));
        cout << (num != t ? 0 : rpt) << '\n';
    }

    return 0;
}
