#include<iostream>
#include<algorithm>
using namespace std;
int fib[45];

int main(){
    ios_base::sync_with_stdio(false);

    fib[1] = 1;
    for(int i = 2;i < 45;i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int n;
    cin >> n;

    while(n--){
        int number;
        bool flag = false;

        cin >> number;

        for(int i = 1;i < 45;i++){
            int sz = number / fib[i];

            if(binary_search(fib,fib + 44,sz) && sz * fib[i] == number){
                flag = true;
                break;
            }
        }
        cout << (flag ? "TAK\n" : "NIE\n");
    }
    return 0;
}
