#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int M = 1<<7;
const char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};

bool check(string &s1, string &s2, int &k){
    vector<int>aLett(M, 0), bLett(M, 0);
    int aLen = 0, bLen = 0, aVow = 0, bVow = 0;
    string a, b;

    for(char c : s1){
        if(c != ' '){
            aLett[c]++;
            a += c;
            aLen++;
        }
    }
    for(char c : s2){
        if(c != ' '){
            bLett[c]++;
            b += c;
            bLen++;
        }
    }

    for(char c : vowels){
        aVow += aLett[c];
        bVow += bLett[c];
    }

    if(aVow != bVow || aLen < k || bLen < k){
        return false;
    }

    for(int i = 1;i <= k;i++){
        if(a[aLen - i] != b[bLen - i]){
            return false;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, k, res = 0;
    string a, b;

    cin >> n >> k;
    getline(cin,a);

    while(n--){
        getline(cin,a);
        getline(cin,b);
        res += check(a,b,k);
    }

    cout << res;
    return 0;
}


















