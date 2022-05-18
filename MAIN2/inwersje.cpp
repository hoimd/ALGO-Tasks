#include<iostream>
using namespace std;

const int M = 1<<19;
int tab[M], temp[M];
uint64_t res;

void mergeSort(int l, int r){
    if(l == r){
        return;
    }
    
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    int i = l, j = mid + 1;
    for(int k = l; k <= r; k++){
        if(j > r || (i <= mid && tab[i] < tab[j])){
            temp[k] = tab[i];
            i++;
        }else{
            res += (mid - i + 1);
            temp[k] = tab[j];
            j++;
        }
    }

    for(int k = l ; k <= r; k++){
         tab[k] = temp[k];
     }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for(int i = 1;i <= n;i++){
        cin >> tab[i];
    }

    mergeSort(1, n);

    for(int i = 1;i <= n;i++){
        cout << tab[i] << ' ';
    }

    cout << '\n' << res;
    return 0;
}
