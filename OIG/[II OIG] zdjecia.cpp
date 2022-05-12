#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int M = 1<<20, shift = 1<<18;
int w[2*M], W[2*M];

struct event{
    int a, b, x, val;
    event(int a,int b,int x,int val) : a(a), b(b), x(x), val(val){}
};

vector<event>events;

bool cmp(event &a,event &b){
    if(a.x != b.x){
        return a.x < b.x;
    }
    return a.val > b.val;
}

void insert(int a, int b, int c){
    a += M;
    b += M;
    w[a] += c;

    if(a < b){
        w[b] += c;
    }

    while(a != 1){
        if(a / 2 != b / 2){
            if(a % 2 == 0){
                w[a + 1] += c;
            }
            if(b % 2 == 1){
                w[b - 1] += c;
            }
        }

        a /= 2;
        b /= 2;

        W[a] = max(W[2 * a] + w[2 * a],W[2 * a + 1] + w[2 * a + 1]);
        W[b] = max(W[2 * b] + w[2 * b],W[2 * b + 1] + w[2 * b + 1]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, res = 0;
    cin >> n;

    while(n--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        events.emplace_back(b + shift, d + shift, a, 1);
        events.emplace_back(b + shift, d + shift, c, -1);
    }

    sort(events.begin(),events.end(),cmp);

    for(auto [a, b, x, val] : events){
        insert(a,b,val);
        res = max(res, W[1]);
    }

    cout << res;
    return 0;
}
