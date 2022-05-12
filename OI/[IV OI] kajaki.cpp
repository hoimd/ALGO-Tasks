#include<iostream>
#include<algorithm>
using namespace std;

const int M = 1<<20;
int tab[M];

int main(){
    ios_base::sync_with_stdio(false);
    int n, w, res = 0;
    cin >> w >> n;

    for(int i = 0;i < n;i++){
        cin >> tab[i];
    }

    sort(tab,tab + n);

    int i = 0, j = n - 1;

    while(i <= j){
        if(tab[i] + tab[j] <= w){
            res++;
            i++;
            j--;
        }else{
            res++;
            j--;
        }
    }

    cout << res;
    return 0;
}
