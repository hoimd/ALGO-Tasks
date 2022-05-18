#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    uint64_t res = 0, t = 0;
    cin >> n;
    
    for(int i = 1;i <= n;i++){
        cin >> k;
        t += !k;
        res += t * k;
    }

    cout << res;
    return 0;
}