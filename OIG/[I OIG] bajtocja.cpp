#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 1<<20;
int Rep[M], Rank[M];
bool res[M];

struct road{
    road(int v, int u, int cost, int nr) : v(v), u(u), cost(cost), nr(nr){}
    int v, u, cost, nr;
};

int Find(int &x){
    return (Rep[x] != x) ? Rep[x] = Find(Rep[x]) : x;
}

void Union(int &a, int &b){
    int x = Find(a), y = Find(b);

    if(Rank[x] > Rank[y]){
        Rep[y] = x;
    }else{
        if(Rank[x] < Rank[y]){
            Rep[x] = y;
        }else{
            if(x != y){
                Rep[y] = x;
                Rank[x]++;
            }
        }
    }
}

vector<road>v, u;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    for(int i = 1;i <= n;i++){
        Rep[i] = i;
    }

    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.emplace_back(a,b,c,i);
    }

    sort(v.begin(),v.end(),[](road &a, road &b){return a.cost < b.cost;});

    v.emplace_back(0, 0, int(2e9 + 1), 0);

    for(auto it = v.begin();it != v.end() - 1;it++){
        if(Find(it->u) != Find(it->v)){
            u.push_back(*it);
        }

        if(it->cost != (it + 1)->cost){
            for(auto [v, u, cost, nr] : u){
                Union(u,v);
                res[nr] = true;
            }
            u.clear();
        }
    }

    for(int i = 0;i < m;i++){
        cout << (res[i] ? "TAK\n" : "NIE\n");
    }

    return 0;
}


















