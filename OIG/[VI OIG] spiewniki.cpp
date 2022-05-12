#include<iostream>
#include<string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, t = 0, res = 0;
    string s;

    cin >> n >> s;
    s.push_back('W');

    for(char c : s){
        if(c == 'Z'){
            t++;
        }else{
            res += t / 3;
            if(t % 3 != 0){
                res++;
            }
            t = 0;
        }
    }

    cout << res;
    return 0;
}
