#include<iostream>
#include<queue>
#include<vector>
#define pos first
#define res second
using namespace std;

const int M = 5005;
pair<int,int>ant[M];
int father[M], n, k;
bool occupied[M], vis[M];
vector<int>G[M], toBlock;
queue<int>Q;

void bfs_direct(int &v){
    for(int i = 1;i <= n;i++){
        vis[i] = false;
    }

    Q.push(v);
    vis[v] = true;

    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int u : G[v]){
            if(!vis[u]){
                father[u] = v;
                vis[u] = true;
                Q.push(u);
            }
        }
    }
}

void bfs_block(int &s){
    for(int v : G[s]){
        if(v != father[s] && !occupied[v]){
            Q.push(v);
            occupied[v] = true;
        }
    }

    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int u : G[v]){
            if(!occupied[u]){
                occupied[u] = true;
                Q.push(u);
            }
        }
    }
}

void move(int &dst){
    for(int i = 1;i <= n;i++){
        occupied[i] = false;
    }

    for(int i = 1;i <= k;i++){
        occupied[ant[i].pos] = true;
    }

    if(occupied[dst]){
        for(int i = 1;i <= k;i++){
            if(ant[i].pos == dst){
                ant[i].res++;
                break;
            }
        }
    }else{
        bfs_direct(dst);

        for(int i = 1;i <= k;i++){
            bfs_block(ant[i].pos);
        }

        bool reached = false;

        while(!reached){
            for(int i = 1;i <= k;i++){
                int newPos = father[ant[i].pos];
                if(!occupied[newPos]){
                    ant[i].pos = newPos;
                    occupied[newPos] = true;
                    toBlock.push_back(newPos);

                    if(newPos == dst){
                        reached = true;
                        ant[i].res++;
                    }
                }
            }
            for(int it : toBlock){
                bfs_block(it);
            }
            toBlock.clear();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int l;
    cin >> n;

    for(int i = 1;i < n;i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cin >> k;

    for(int i = 1;i <= k;i++){
        cin >> ant[i].pos;
        occupied[ant[i].pos] = true;
    }

    cin >> l;

    while(l--){
        int d;
        cin >> d;
        move(d);
    }

    for(int i = 1;i <= k;i++){
        cout << ant[i].pos << ' ' << ant[i].res << '\n';
    }

    return 0;
}
