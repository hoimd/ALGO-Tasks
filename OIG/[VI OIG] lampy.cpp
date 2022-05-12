#include<iostream>
#include<set>
using namespace std;

const int M = 1<<20;

struct Interval{
    double length, trInside;
}tab[M];

set<pair<double,int>>s;

double areaUp(double length, double trInside){
    return (length / trInside) * (length / trInside) / 4;
}

double bestCover(Interval &x){
    return (areaUp(x.length, x.trInside + 1) * (x.trInside + 1))
         - (areaUp(x.length, x.trInside) * (x.trInside));
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, k, prev, t;
    double res = 0;

    cin >> n >> k >> t >> prev;

    for(int i = 0;i < n - 1;i++){
        cin >> t;
        tab[i].length = t - prev;
        tab[i].trInside = 1;
        s.emplace(bestCover(tab[i]),i);
        prev = t;
    }

    while(k--){
        int i = s.begin()->second;
        s.erase(s.begin());
        tab[i].trInside++;
        s.emplace(bestCover(tab[i]),i);
    }

    for(int i = 0;i < n - 1;i++){
        res += tab[i].trInside * areaUp(tab[i].length,tab[i].trInside);
    }

    cout.precision(12);
    cout << fixed << res;

    return 0;
}
