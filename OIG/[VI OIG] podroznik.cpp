#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, ms = 0, mn = 0, me = 0, mw = 0,tx = 0, ty = 0;

    cin >> n;

    while(n--){
        int k, vx = 0, vy = 0;
        string s;

        cin >> k >> s;

        for(char c : s){
            switch(c){
                case 'N' : vy++;break;
                case 'S' : vy--;break;
                case 'E' : vx++;break;
                case 'W' : vx--;break;
            }
            mw = min(mw,tx + vx);
            me = max(me,tx + vx);
            mn = max(mn,ty + vy);
            ms = min(ms,ty + vy);
        }

        tx += (k - 1) * vx;
        ty += (k - 1) * vy;

        vy = vx = 0;

        for(char c : s){
            switch(c){
                case 'N' : vy++;break;
                case 'S' : vy--;break;
                case 'E' : vx++;break;
                case 'W' : vx--;break;
            }
            mw = min(mw,tx + vx);
            me = max(me,tx + vx);
            mn = max(mn,ty + vy);
            ms = min(ms,ty + vy);
        }

        tx +=  vx;
        ty +=  vy;
    }

    cout << mn - ms << ' ' << me - mw;
    return 0;
}


















