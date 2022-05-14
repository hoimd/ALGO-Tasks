#include<iostream>
#define val first
#define pos second
using namespace std;

const int M = 1<<17, INF = 2e9 + 1;
pair<int,int>W[2*M];
int w[2*M];

pair<int,int> operator+(pair<int,int> &a, int &b){
    return make_pair(a.first + b, a.second);
}

void insert(int a, int b, int c){
    a += M;
    b += M;
    w[a] += c;

    if(a < b){
        w[b] += c;
    }

    while(a != 1){
        if (a / 2 != b / 2){
            if(a % 2 == 0){
                w[a + 1] += c;
            }
            if(b % 2 == 1){
                w[b - 1] += c;
            }
        }

        a /= 2;
        b /= 2;

        W[a] = min(W[2 * a] + w[2 * a], W[2 * a + 1] + w[2 * a + 1]);
        W[b] = min(W[2 * b] + w[2 * b], W[2 * b + 1] + w[2 * b + 1]);
    }
}

inline void initTree(){
    for(int i = 1;i <= M;i++){
        W[i].val = INF;
    }

    for(int i = M + 1;i < 2 * M;i++){
        W[i].pos = i - M;
        w[i] = INF;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, k;

    initTree();
    cin >> n >> m >> k;

    for(int i = 1;i <= n;i++){
        int t;
        cin >> t;
        insert(i, i, t - INF);
    }

    while(m--){
        int pos = W[1].pos;
        insert(pos, min(n, pos + k - 1), 1);
    }

    cout << W[1].val;
    return 0;
}
