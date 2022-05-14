#include<iostream>
#include<vector>
using namespace std;

const int M = 1<<20;
int obs[M], flag[M];
vector<int>toMark, last;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, good = 1;
    flag[1] = true;

    cin >> n >> m;

    for(int i = 1;i <= n;i++){
        toMark.push_back(i);
    }

    for(int hr = 0;hr < m;hr++){
        for(int it : last){
            obs[it] = false;
            good += flag[it];
            toMark.push_back(it);
        }
        last.clear();

        int a, b;
        cin >> a;

        while(a--){
            cin >> b;
            obs[b] = true;
            good -= flag[b];
            last.push_back(b);
        }

        if(good > 0){
            if(!obs[n]){
                cout << hr;
                return 0;
            }

            for(int it : toMark){
                if(!obs[it] && !flag[it]){
                    flag[it] = true;
                    good++;
                }
            }
            toMark.clear();
        }
    }

    cout << m;
    return 0;
}
