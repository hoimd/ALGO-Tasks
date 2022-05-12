#include<iostream>
using namespace std;

const int M = 1<<20;
double n, m, d, res = 1e9 + 1;
double len[M], lim[M];

inline void first_pass(){
    double cr = 0, rem = m;
    int last = 0;
    for(int i = 0;i < n;i++){
        if(len[i] >= rem){
            res = min(res,cr + (rem / lim[i]));
            cr -= len[last] / lim[last];
            rem += len[last];
            last++;
            i--;
        }else{
            rem -= len[i];
            cr += len[i] / lim[i];
        }
    }
}

inline void second_pass(){
    double cr = 0, rem = m;
    int last = n - 1;
    for(int i = n - 1;i >= 0;i--){
        if(len[i] >= rem){
            res = min(res,cr + rem / lim[i]);
            cr -= len[last] / lim[last];
            rem += len[last];
            last--;
            i++;
        }else{
            rem -= len[i];
            cr += len[i] / lim[i];
        }
    }
}

inline void in(){
    cin >> n >> m >> d;
    int last = 0, t;

    cin >> last >> lim[0];
    for(int i = 1;i < n;i++){
        cin >> t >> lim[i];
        len[i - 1] = t - last;
        last = t;
    }
    len[int(n) - 1] = d - last;
}
int main(){
    ios_base::sync_with_stdio(false);

    in();
    first_pass();
    second_pass();

    cout.precision(3);
    cout << fixed << res;
    return 0;
}
