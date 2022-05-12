#include<iostream>
#include<algorithm>
using namespace std;

const int M = 1<<8;
string tab[M];

bool cmp(string &a, string &b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i = 0;i < n;i++){
        cin >> tab[i];
    }

    sort(tab,tab + n,cmp);

    for(int i = 0;i < n;i++){
        cout << tab[i] << '\n';
    }

    return 0;
}


















