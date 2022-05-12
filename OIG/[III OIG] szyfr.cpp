#include<iostream>
#include<string>
using namespace std;

const int M = 1<<7;
int tab[M;

int main(){
    ios_base::sync_with_stdio(false);
    int n, mx = 0;
    char c, d;
    string s;

    cin >> n >> c >> s;

    for(char t : s){
        ++tab[t];
        if(tab[t] > mx){
            mx = tab[t];
            d = t;
        }
    }

    int shift = d - c;

    if(shift < 0 ){
        shift += 26;
    }

    for(char t : s){
        if(t - shift < 'A') {
            cout << char(t - shift + 26);
        }else{
            cout << char(t - shift);
        }
    }

    return 0;
}
