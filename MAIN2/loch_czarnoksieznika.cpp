#include<iostream>
#include<queue>
#define x first
#define y second
using namespace std;

const int M = 1<<10, INF = 1e9 + 1;
int tab[M][M];
queue<pair<int,int>>q;

int bfs(pair<int,int> &start, pair<int,int> &exit){
    static const pair<int,int> vec[] = {{1,0},{0,1},{-1,0},{0,-1}};

    tab[start.y][start.x] = 0;
    q.emplace(start.x,start.y);

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for(auto d : vec){
            if(tab[y + d.y][x + d.x] > tab[y][x] + 1){
                if(make_pair(x + d.x,y + d.y) == exit){
                    return tab[y][x] + 1;
                }
                tab[y + d.y][x + d.x] = tab[y][x] + 1;
                q.emplace(x + d.x, y + d.y);
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int z;
    cin >> z;

    while(z--){
        int n, m;
        pair<int,int>start, exit;

        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                char c;
                cin >> c;

                if(c != '#'){
                    tab[i][j] = INF;
                    switch(c){
                        case '@' : start = make_pair(j,i);break;
                        case '>' : exit = make_pair(j,i);break;
                    }
                }
            }
        }
        
        int res = bfs(start,exit);
        
        if(res){
            cout << res << '\n';
        }else{
            cout << "NIE\n";
        }

        for(int i = 1;i <= n;i++){
            for(int j = 1; j <= m; j++){
                tab[i][j] = 0;
            }
        }

        while(!q.empty()){
            q.pop();
        }
    }
    
    return 0;
}