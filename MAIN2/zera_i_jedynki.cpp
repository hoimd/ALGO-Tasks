#include<iostream>
using namespace std;

const int M = 1<<19, MM = 2 * M;
int bestL[MM], bestR[MM], zero[MM], best[MM];

void insert(int a){
    a += M;
    bestL[a] = bestR[a] = zero[a] = !bestL[a];

    for(a /= 2; a > 0; a /= 2){
        zero[a] = zero[2 * a] && zero[2 * a + 1];
        bestL[a] = bestL[2 * a] + zero[2 * a] * bestL[2 * a + 1];
        bestR[a] = bestR[2 * a + 1] + zero[2 * a + 1] * bestR[2 * a];
        best[a] = max(max(best[2 * a], best[2 * a + 1]), bestR[2 * a] + bestL[2 * a + 1]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 1;i <= n;i++){
        char c;
        cin >> c;
        if(c == '0'){
            insert(i);
        }
    }

    while(m--){
        int a;
        cin >> a;
        insert(a);
        cout << best[1] << '\n';
    }
    
    return 0;
}
