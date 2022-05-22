#include<iostream>
using namespace std;

const int M = 1<<18;
int tree[2*M];

void insert(int a, int val){
    a += M;
    tree[a] = val;

    for(a /= 2; a > 0; a /= 2){
        tree[a] = max(tree[2 * a],tree[2 * a + 1]);
    }
}

int query(int a, int b){
    a += M;
    b += M;
    int res = max(tree[a],tree[b]);

    while(a / 2 != b / 2){
        if(a % 2 == 0){
            res = max(res,tree[a + 1]);
        }
        if(b % 2 == 1){
            res = max(res,tree[b - 1]);
        }
        a /= 2;
        b /= 2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 1;i <= n;i++){
        int a;
        cin >> a;
        insert(i,a);
    }

    while(m--){
        int a, b;
        string cmd;

        cin >> cmd;
        if(cmd == "MAX"){
            cin >> a >> b;
            cout << query(a,b) << '\n';
        }else{
            cin >> a >> b;
            insert(a,b);
        }
    }
    
    return 0;
}
