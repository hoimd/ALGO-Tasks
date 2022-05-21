#include<iostream>
using namespace std;

const int M = 1<<20;
int c[M], l[M], tab[M], rep[M];
bool flag[M];

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, ok = 0, res = 0;
    uint64_t len = 0;

    cin >> n >> m;

    for(int i = 1;i <= m;i++){
        cin >> l[i];
        len += l[i];
    }

    if(len > n){
        cout << 0;
        return 0;
    }

    for(int i = 1;i <= m;i++){
        int t;
        cin >> t;
        c[t] = l[i];
    }

    for(int i = 1;i <= n;i++){
        cin >> tab[i];
    }

    for(int i = 1;i <= len;i++) {
        int t = tab[i];
        rep[t]++;

        if(c[t]){
            if(rep[t] == c[t] && !flag[t]){
                flag[t] = true;
                ok++;
            }else{
                if(rep[t] != c[t] && flag[t]){
                    flag[t] = false;
                    ok--;
                }
            }
        }
    }

    if(ok == m){
        res++;
    }

    for(int i = len + 1;i <= n;i++){
        int b = tab[i], a = tab[i - len];
        rep[a]--;
        rep[b]++;

        if(c[a]){
            if(rep[a] == c[a] && !flag[a]){
                flag[a] = true;
                ok++;
            }else{
                if(rep[a] != c[a] && flag[a]){
                    flag[a] = false;
                    ok--;
                }
            }
        }

        if(c[b]){
            if(rep[b] == c[b] && !flag[b]){
                flag[b] = true;
                ok++;
            }else{
                if(rep[b] != c[b] && flag[b]){
                    flag[b] = false;
                    ok--;
                }
            }
        }

        if(ok == m){
            res++;
        }
    }

    cout << res;
    return 0;
}
