#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,string>>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0;i < n;i++){
        int a;
        string s;
        cin >> s >> a;
        v.emplace_back(a,s);
    }

    sort(v.begin(),v.end());

    for(auto it = v.begin(); it!= v.end(); it++){
        auto it2 = lower_bound(v.begin(), v.end(), make_pair(m - it->first, it->second));
        if(it->first + it2->first == m){
            cout << it->second << ' ' << it2->second;
            return 0;
        }
    }

    cout << "NIE";
    return 0;
}
