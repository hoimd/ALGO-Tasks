#include<iostream>
#include<cmath>
#define x first
#define y second
using namespace std;

int nwd(int a, int  b){
    if(a < b){
        swap(a, b);
    }
    if(b == 0){
        return a;
    }
    return nwd(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    pair<int,int> oldPoint, newPoint, firstPoint;
    int n, dx, dy, nw;

    cin >> n >> oldPoint.x >> oldPoint.y;

    firstPoint.x = oldPoint.x;
    firstPoint.y = oldPoint.y;

    for(int i = 0;i < n - 1;i++){
        cin >> newPoint.x >> newPoint.y;
        dx = newPoint.x - oldPoint.x;
        dy = newPoint.y - oldPoint.y;
        nw = nwd(abs(dx),abs(dy));
        dx /= nw;
        dy /= nw;

        while(oldPoint != newPoint){
            cout << oldPoint.x << ' ' << oldPoint.y << '\n';
            oldPoint.x += dx;
            oldPoint.y += dy;

        }
        oldPoint.x = newPoint.x;
        oldPoint.y = newPoint.y;
    }

    dx = firstPoint.x - oldPoint.x;
    dy = firstPoint.y - oldPoint.y;
    nw = nwd(abs(dx),abs(dy));
    dx /= nw;
    dy /= nw;

    while(oldPoint != firstPoint){
        cout << oldPoint.x << ' ' << oldPoint.y << '\n';
        oldPoint.x += dx;
        oldPoint.y += dy;
    }
    return 0;
}
