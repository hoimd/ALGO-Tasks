#include <iostream>
using namespace std;

const int M = 1<<20;
int r[M], s[M];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i = 0;i < n;i++){
        char z;
        cin >> z;
        if(z == '1'){
            s[i] = 1;
        }
    }

    int  j = 0, i = 1, k;
    uint64_t res = 0;

    while(i < n){
       while(i > j && i + j < n && s[i - j - 1] != s[i + j]){
           j++;
       }

       res += j;
       r[i] = j;

       for(k = 1;k <= j && r[i - k] != j - k;k++){
           r[i + k] = min(j - k,r[i - k]);
           res += r[i + k];
       }

       i += k;
       j = max(j - k, 0);
    }

    cout << res;
    return 0;
}
