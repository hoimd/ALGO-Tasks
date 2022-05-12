#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, x, y, res = 0;

    cin >> n >> k >> x >> y;

    while(n--){
        int a, b;
        cin >> a >> b;
        if(((x-a)*(x-a) + (y-b)*(y-b)) > k*k){
            res++;
        }
    }

    cout << res;
    return 0;
}


















