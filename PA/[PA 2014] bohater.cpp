#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct mnstr{
    mnstr(int n, int d, int p) : nr(n), dmg(d), potion(p) {}
    int nr, dmg, potion;
};

vector<mnstr>v, u;

int main(){
    ios_base::sync_with_stdio(false);
    int64_t n, health;

    cin >> n >> health;

    for(int i = 1;i <= n;i++){
        int d, p;
        cin >> d >> p;
        if(p - d >= 0){
            v.emplace_back(i,d,p);
        }else{
            u.emplace_back(i,d,p);
        }
    }

    sort(v.begin(),v.end(),[](mnstr &a, mnstr &b){return a.dmg < b.dmg;});
    sort(u.begin(),u.end(),[](mnstr &a, mnstr &b){return a.potion > b.potion;});

    for(auto it : v){
        if(health - it.dmg <= 0){
            cout << "NIE";
            return 0;
        }else{
            health += it.potion - it.dmg;
        }
    }

    for(auto it : u){
        if(health - it.dmg <= 0){
            cout << "NIE";
            return 0;
        }else{
            health += it.potion - it.dmg;
        }
    }

    cout << "TAK" << endl;
    for(auto it : v){
        cout << it.nr << ' ';
    }

    for(auto it : u){
        cout << it.nr << ' ';
    }

    return 0;
}
