#include<iostream>
using namespace std;

const int M = 1<<7;
int flower[M];

int main(){
    ios_base::sync_with_stdio(false);
    int l, n, w = 0;
    bool flag = true;

    cin >> n >> l;
    for(int i = 0;i < l;i++){
        char zn;
        cin >> zn;
        flower[zn]++;
    }

    for(int i = 49;i < n + 49;i++){
        cin >> l;
        if(flower[i] > l){
            flag = false;
            break;
        }
        else{
            w += l - flower[i];
        }
    }

    if(flower[68] > w){
        flag = false;
    }

    cout << (flag ? "TAK" : "NIE");
    return 0;
}
