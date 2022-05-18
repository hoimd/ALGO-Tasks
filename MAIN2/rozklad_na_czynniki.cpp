#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while(q--){
        int n, div = 2;
        bool print = false;

        cin >> n;
        cout << n << " = ";
        int num = n;

        while(div * div <= num){
            if(n % div == 0){
                if(print){
                    cout << '*';
                }

                int rep = 0;
                while(n % div == 0){
                    n /= div;
                    rep++;
                }

                cout << div;
                if(rep > 1){
                    cout << '^' << rep;
                }

                print = true;
            }
            
            if(div > 2){
                div += 2;
            }else{
                div++;
            }
        }

        if(n > 1){
            if(print){
                cout << '*';
            }
            cout << n;
        }
        cout << '\n';
    }

    return 0;
}
