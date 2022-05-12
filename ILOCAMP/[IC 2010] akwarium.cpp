#include<iostream>
#include<algorithm>
using namespace std;

const int M = 1<<20;
int res[M];

struct st{
    unsigned int w, a, nr;
}fish[M];

bool cmp(st &A, st &B){
    if(A.w != B.w) {
        return A.w > B.w;
    }
    return A.a > B.a;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, day = 1, q;
    cin >> n;

    for(int i = 0;i < n;i++){
        cin >> fish[i].w >> fish[i].a;
        fish[i].w *= 2;
        fish[i].nr = i + 1;
    }

    sort(fish,fish + n,cmp);

    while(n > 0){
        for(int i = 0;i < n;i++){
            int t = n - 1;
            fish[i].w += fish[t].w * 2;
            res[fish[t].nr] = day;
            n--;
        }
        day++;
        sort(fish,fish + n,cmp);
    }

    cin >> q;

    while(q--){
        int a, b;
        cin >> a >> b;
        cout << (res[a] > b ? "TAK\n" : "NIE\n");
    }
    return 0;
}
