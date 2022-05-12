#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int M = 1<<7;
const char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};

bool check(string &a, string &b, int &k){
    vector<int>v(M, 0), u(M, 0);

    for(char i : a){
        v[i]++;
    }
    for(char i : b){
        u[i]++;
    }

    int sum = 0, sum1 = 0;

    for(char c : vowels){
        sum += v[c];
        sum1 += u[c];
    }

    if(sum != sum1){
        return false;
    }

    sum = sum1 = 0;

    for(int i = 'a';i <= 'z';i++){
        sum += v[i];
        sum1 += u[i];
    }

    if(sum < k || sum1 < k){
        return false;
    }

    auto it = a.rbegin(), it2 = b.rbegin();

    for(int i = 0;i < k;i++){
        if(*it != *it2){
            return false;
        }

        it++;
        it2++;

        while(*it == ' '){
            it++;
        }
        while(*it2 == ' '){
            it2++;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, res = 0;
    string a, b;

    cin >> n >> k;
    getline(cin, a);

    while(n--){
        getline(cin, a);
        getline(cin, b);
        res += check(a, b, k);
    }

    cout << res;
    return 0;
}


















