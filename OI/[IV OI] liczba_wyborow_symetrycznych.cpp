#include<iostream>
#include<vector>
using namespace std;

const int M = 1<<6;
uint64_t res = 0;
int skipped[M], depth = -1, pom, n;
string word;

struct vertex{
    string word;
    vector<int>next;
}v[M];

inline void in(){
    cin >> n;
    for(int i = 1;i <= 2 * n;i++){
        cin >> v[i].word;
    }
    for(int i = 1;i < n;i++){
        if(v[i+1].word != v[i + n + 1].word){
            v[i].next.push_back(i + n + 1);
        }else {
            skipped[i] = 1;
        }
        v[i].next.push_back(i + 1);
    }
    for(int i = n + 1;i < 2 * n;i++){
        v[i].next.push_back(i - n + 1);
        if(v[i + 1].word != v[i - n + 1].word){
            v[i].next.push_back(i + 1);
        }
    }

    v[0].next.push_back(1);

    if(v[1].word != v[n + 1].word){
        v[0].next.push_back(n + 1);
    }else{
        skipped[0] = 1;
    }
}

bool check(){
    int p = 0, k = word.size() - 1;
    while(p < k){
        if(word[p++] != word[k--]){
            return false;
        }
    }
    return true;
}
void dfs(int u){
    depth++;
    pom += skipped[depth];
    word += v[u].word;

    if(depth == n){
        if(check()){
            res += 1 << pom;
        }
    }

    for(int i : v[u].next){
        dfs(i);
    }

    word.resize(word.size() - v[u].word.size());
    pom -= skipped[depth];
    depth--;
}

int main(){
    ios_base::sync_with_stdio(false);

    in();
    dfs(0);
    cout << res;

    return 0;
}
