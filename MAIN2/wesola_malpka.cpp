#include<iostream>
using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int c = b;
        b = a % b;
        a = c;
    }

    return a;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while(n--){
        int a, b;
        cin >> a >> b;
        cout << a / gcd(a,b) << '\n';
    }

    return 0;
}
