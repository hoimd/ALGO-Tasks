#include<iostream>
#include<string>
#include<set>
using namespace std;

set<int>s;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string a, b;

    cin >> n >> a >> b;

    for(int i = 0;i < n;i++){
        if(a[i] != b[i]){
            s.insert(i);
        }
    }

    cin >> n;

    while(n--){
        int x, y;
        cin >> x >> y;

        swap(a[x], b[y]);

        if(a[x] == b[x]){
            s.erase(x);
        }else{
            s.insert(x);
        }

        if(a[y] == b[y]){
            s.erase(y);
        }else{
            s.insert(y);
        }

        if(s.empty()){
            cout << 0 << '\n';
        }else{
            int i = *s.begin();
            cout << (a[i] > b[i] ? 1 : 2) << '\n';
        }
    }
    return 0;
}


















