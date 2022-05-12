#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int res = 0, pos = 0, prev = 0, n;

    cin >> n;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        if(x > prev + i - pos){
            pos = i;
            prev = x;
        }
        res = max(res,prev + x + i - pos);
    }

    cout << res;
    return 0;
}
