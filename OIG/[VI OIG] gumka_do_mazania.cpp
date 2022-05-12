#include <iostream>
#include <string>
using namespace std;

const int M = 10005;
int curPos[M], newPos[M];
string word[M];


int main(){
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;

    for(int i = 0;i < n;i++){
        cin >> word[i];
    }

    string res;
    char c = 'z';

    while(c >= 'a'){
        int found = 0;
        for(int i = 0;i < n;i++){
            for(int j = curPos[i];j < word[i].size();j++){
                if(word[i][j] == c){
                    newPos[i] = j;
                    found++;
                    break;
                }
            }
        }

        if(found == n){
            res += c;
            for(int i = 0;i < n;i++) {
                curPos[i] = newPos[i] + 1;
            }
        }else {
            c--;
        }
    }

    cout << (res > "bitek" ? res : "bitek");
    return 0;
}


















