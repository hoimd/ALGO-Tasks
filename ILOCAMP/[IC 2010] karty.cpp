#include<iostream>
#include<string>
#include<deque>
using namespace std;

deque<int>q;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    string s;
    cin >> n >> m >> s;

    for(int i = 1;i <= n;i++){
        q.push_front(i);
    }

    for(char c : s){
        if(c == 'A'){
            q.push_front(q.back());
            q.pop_back();
        }else{
            int t = q.back();
            q.pop_back();
            q.push_front(q.back());
            q.pop_back();
            q.push_back(t);
        }
    }

    cout << q.back();
    return 0;
}
