#include<iostream>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;

vector<pair<int,int>>v, p;

int solve(){
    int rep = 1, res = 1, n;
    cin >> n;

    for(int i = 0;i < n;i++){
        int x, y;
        cin >> x >> y;
        p.emplace_back(x,y);
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            v.emplace_back(p[j].x + p[i].x, p[j].y + p[i].y);
        }
    }

    sort(v.begin(),v.end());
    auto prev = v.front();

    for(int i = 1;i < v.size();i++){
        if(v[i] != prev){
            res = max(res,rep);
            rep = 1;
            prev = v[i];
        }else{
            rep++;
        }
    }

    p.clear();
    v.clear();

    return n - max(res,rep);
}

int main(){
    ios_base::sync_with_stdio(false);
    int z;
    cin >> z;

    while(z--){
        cout << solve() << '\n';
    }
    return 0;
}

