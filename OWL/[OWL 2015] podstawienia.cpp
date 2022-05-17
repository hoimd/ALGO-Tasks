#include<iostream>
using namespace std;

int rep[10];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> s;

    for(auto it : s){
        rep[it - '0']++;
    }

    cin >> n;

    while(n--){
        int l, res = 0;
        cin >> l >> s;

        int t = rep[l];
        rep[l] = 0;

        for(auto it : s){
            rep[it - '0'] += t;
        }

        for(int i = 0;i < 10;i++){
            rep[i] %= 9;
            res =(res + i * rep[i]) % 9;
        }

        cout << res << '\n';
    }
    return 0;
}
