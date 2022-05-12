#include<iostream>
#include<deque>
#define x first
#define y second
using namespace std;

const int M = 1<<10;
deque<pair<int,int>>q;
char tab[M][M];

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, r;
    char dir;

    cin >> n >> m >> r >> dir;

    for(int i = 1; i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> tab[i][j];
            if(tab[i][j] == 'W'){
                q.emplace_back(j,i);
            }
        }
    }

    for(int i = 1;i <= r;i++){
        char c;
        cin >> c;

        if(c == 'L'){
            switch (dir){
                case 'N' : dir = 'W';break;
                case 'S' : dir = 'E';break;
                case 'E' : dir = 'N';break;
                case 'W' : dir = 'S';break;
            }
        }

        if(c == 'P'){
            switch (dir){
                case 'N' : dir = 'E';break;
                case 'S' : dir = 'W';break;
                case 'E' : dir = 'S';break;
                case 'W' : dir = 'N';break;
            }
        }

        auto [x, y] = q.back();

        switch(dir){
            case 'N' : y--;break;
            case 'S' : y++;break;
            case 'E' : x++;break;
            case 'W' : x--;break;
        }

        if(x < 1 || x > m || y < 1 || y > n || tab[y][x] == 'W'){
            cout << i;
            return 0;
        }

        if(tab[y][x] != 'J'){
            tab[q.front().y][q.front().x] = 0;
            q.pop_front();
        }

        q.emplace_back(x,y);
        tab[y][x] = 'W';

    }

    cout << "OK";
    return 0;
}
