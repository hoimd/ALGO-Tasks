#include<iostream>
#include<vector>
using namespace std;

const int M = 1<<20;
bool gift[M], used[M];
int last[M];
vector<uint64_t>res;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, mxSize = 0;
    uint64_t clients = 0;
    cin >> m;

    while(m--){
        int t;
        cin >> t;
        gift[t] = true;
        mxSize = t;
    }

    cin >> n;

    while(n--){
        int t;
        uint64_t client = clients;

        cin >> t;

        while(client < clients + t){
            if(last[t] + t > mxSize){
                break;
            }

            last[t] += t;

            if(!used[last[t]]){
                used[last[t]] = true;
                client++;

                if(gift[last[t]]){
                    res.push_back(client);
                    gift[last[t]] = false;
                }
            }
        }
        clients += t;
    }

    cout << res.size() << '\n';
    for(auto it : res){
        cout << it << '\n';
    }

    return 0;
}
