#include<iostream>
#include<stack>
using namespace std;

stack<char>s;

int val(char c){
    switch (c){
        case '{' : return -3;
        case '}' : return 3;
        case '[' : return -2;
        case ']' : return 2;
        case '(' : return -1;
        case ')' : return 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, res = 0, depth = 0;

    cin >> n;

    while(n--){
        char c;
        cin >> c;
        if(val(c) < 0){
            depth++;
            s.push(c);
            res = max(res,depth);
        }else{
            if(!s.empty() && val(c) + val(s.top()) == 0){
                depth--;
                s.pop();
            }else {
                cout << "NIE";
                return 0;
            }
        }
    }

    if(s.empty()){
        cout << res;
    }else{
        cout << "NIE";
    }

    return 0;
}
