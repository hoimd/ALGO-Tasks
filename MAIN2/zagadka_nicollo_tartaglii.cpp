#include<iostream>
#define int uint64_t
using namespace std;
int p, q;

int e(int &x){
    return (x * x * x) + p * x;
}

int binsearch(int l, int r){
    while(l <= r){
        if(l == r){
            return l;
        }
        int mid = (l + r) / 2;
        if(e(mid) < q){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int z;
    cin >> z;

    while(z--){
        cin >> p >> q;
        int b = binsearch(0,int(2e6));

        if(e(b) == q){
            cout << b << '\n';
        }else {
            cout << "NIE\n";
        }
    }
    return 0;
}
