 #include<iostream>
using namespace std;

const int M = 1<<16;
int w[M*2], W[M*2];

void insert(int a, int b, int c){
    a += M;
    b += M;
    w[a] += c;

    if(a < b){
        w[b] += c;
    }

    while(a != 1){
        if (a / 2 != b / 2){
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

void path(int v, int p[]){
    int tab[30], i = 0, sum = 0;

    while(v != 0){
        tab[i] = v;
        i++;
        v /= 2;
    }

    for(i--;i >= 0;i--){
        sum += w[tab[i]];
        p[i] = sum;
    }
}

int query(int a, int b){
    a += M;
    b += M;
    int left[30], right[30], d = 0;

    path(a,left);
    path(b,right);

    int res = a < b ? max(left[0],right[0]) : left[0];

    while(a / 2 != b / 2){
        if(a % 2 == 0){
            res = max(res,W[a + 1] + w[a + 1] + left[d + 1]);
        }
        if(b % 2 == 1){
            res = max(res,W[b - 1] + w[b - 1] + right[d + 1]);
        }

        a /= 2;
        b /= 2;
        d++;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, z;
    cin >> n >> m >> z;

    while(z--){
        int a, b, c;
        cin >> a >> b >> c;

        if(m - query(a,b - 1) < c){
            cout << "N\n";
        }else{
            cout << "T\n";
            insert(a,b - 1,c);
        }
    }
    return 0;
}
