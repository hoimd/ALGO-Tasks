#include<iostream>
using namespace std;

const int M = 1<<20;
int height[M], ending[M], n, m, k;

bool check(int exp){
    for(int i = 1;i <= n;i++){
        ending[i] = 0;
    }

    int watSum = 0, watCount = 0;

    for(int i = 1;i <= n;i++){
        watSum -= ending[i];
        if(height[i] + watSum < exp){
            int delta = exp - (height[i] + watSum);
            watCount += delta;
            watSum += delta;
            if(i + k <= n){
                ending[i + k] = delta;
            }
        }
    }

    return watCount <= m;
}

int binsearch(int l, int r){
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(check(mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    int minHeight = 1e9 + 1;
    cin >> n >> m >> k;

    for(int i = 1;i <= n;i++){
        cin >> height[i];
        minHeight = min(minHeight,height[i]);
    }

    cout << binsearch(minHeight, minHeight + m);
    return 0;

}