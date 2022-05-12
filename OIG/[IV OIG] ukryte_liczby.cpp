#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    uint64_t n, t = 0, res = 0;
    string w;

    cin >> n >> w;

    for(int i = n - 1;i >= 0;i--){
        if(w[i] - '0' < 10){
            res += (w[i] - '0') * pow(10,t);
            t++;
        }else {
            t = 0;
        }
    }

    cout << res;
    return 0;
}


















