#include<iostream>
using namespace std;

const int MOD = 1e4;

int pow(int a, int n){
    if(n == 1){
        return a % MOD;
    }
    if(n % 2 == 0){
        int s = pow(a, n / 2);
        return (s * s) % MOD;
    }else{
        int s = pow(a, n - 1);
        return (a * s) % MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while(n--){
        int a, b;
        cin >> a >> b;
        cout << pow(a + 1, b) << '\n';
    }

    return 0;
}
