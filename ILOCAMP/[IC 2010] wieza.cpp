#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>v;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, prev = -1;
    cin >> n >> m;

    for(int i = 1;i <= n;i++){
        int t;
        cin >> t;
        if(t > prev){
            v.push_back(t);
            prev = t;
        }else{
            v.push_back(prev);
        }

    }

    while(m--){
        int t;
        cin >> t;
        cout << lower_bound(v.begin(),v.end(),t) - v.begin() << ' ';
    }

    return 0;
}
