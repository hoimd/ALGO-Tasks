#include<iostream>
using namespace std;

int nwd(int a, int  b){
    if(a < b){
        swap(a, b);
    }
    if(b == 0){
        return a;
    }
    return nwd(b, a % b);
}
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    while(n--){
        int a, b;
        cin >> a >> b;
        cout << a / nwd(a,b) << '\n';
    }

    return 0;
}
