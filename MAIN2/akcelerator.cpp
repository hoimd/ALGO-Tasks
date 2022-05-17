#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, prev, rep;
    cin >> n;

    while(n--){
        int num;
        cin >> num;
        if(num != prev){
            v.emplace_back(prev,rep);
            prev = num;
            rep = 1;
        }else{
            rep++;
        }
    }

    v.emplace_back(prev,rep);
    cin >> n;

    while(n--){
        int num;
        cin >> num;
        auto it = lower_bound(v.begin() + 1, v.end(), make_pair(num,0));
        cout << (it->first != num ? 0 : it->second) << '\n';
    }

    return 0;
}
