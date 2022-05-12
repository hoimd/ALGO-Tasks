#include<iostream>
#include<queue>
#define int uint64_t
using namespace std;

queue<int>Q;
vector<int>v;

bool isPrime(int &x){
    if(x < 2){
        return false;
    }
    for(int i = 2;i*i <= x;i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}

int32_t main(){
    int tab[] = {1, 3, 5, 7, 9};
    int a, b, res = 0;

    cin >> a >> b;

    Q.push(2);
    Q.push(3);
    Q.push(5);
    Q.push(7);

    while(!Q.empty()){
        int Top = Q.front();
        Q.pop();
        v.push_back(Top);
        for(int i : tab){
            int t = 10 * Top + i;
            if(isPrime(t)){
                Q.push(t);
            }
        }
    }

    for(int i : v){
        if(a <= i && i <= b){
            res++;
        }
    }

    cout << res;
    return 0;
}
