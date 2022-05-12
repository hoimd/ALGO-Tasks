#include<iostream>
using namespace std;

const int M = 1<<20, INF = 1e9 + 1;

struct comp{
    int mins, maxs, minw, maxw;
}tab[M];

int main(){
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;

    while(q--){
        int minw = INF, mins = INF, maxw = 0, maxs = 0, n;

        cin >> n;

        for(int i = 0;i < n;i++){
            cin >> tab[i].mins >> tab[i].maxs >> tab[i].minw >> tab[i].maxw;

            mins = min(mins,tab[i].mins);
            minw = min(minw,tab[i].minw);
            maxs = max(maxs,tab[i].maxs);
            maxw = max(maxw,tab[i].maxw);
        }

        bool flag = false;

        for(int i = 0;i < n;i++)
            if(tab[i].mins == mins && tab[i].maxs == maxs && tab[i].minw == minw && tab[i].maxw == maxw){
                flag = true;
                break;
            }
        cout << (flag ? "TAK\n" : "NIE\n");
    }
    return 0;
}
