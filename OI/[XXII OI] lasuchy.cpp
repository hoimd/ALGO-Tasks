#include<iostream>
#define cal first
#define half second
using namespace std;

const int M = 1<<20;
int tab[M];
pair<int,int>cake[M];

int main(){
    ios_base::sync_with_stdio(false);
    bool flag = false;
    int index, opt, n;

    cin >> n;

    for(int i = 1;i <= n;i++){
        cin >> cake[i].half;
        cake[i].cal = 2 * cake[i].half;
    }

    cake[0].cal = 1e9 + 1;

    for(int i = 1,j = 2;i < n;i++,j++){
        if(cake[i].cal <= cake[j].cal){
            cake[j].cal = cake[j].half;
            tab[i] = j;
        }else{
            cake[i].cal = cake[i].half;
            tab[i] = i;
            index = i - 1;

            while(true){
                if(cake[index + 1].cal >= cake[index].cal) {
                    opt = index + 1;
                }else {
                    opt = index;
                }

                if(tab[index] == opt){
                    break;
                }else{
                    cake[opt].cal = cake[opt].half;
                    tab[index] = opt;
                    index--;
                }
            }
        }
    }

    if(cake[n].cal <= cake[1].cal){
        cake[1].cal = cake[1].half;
        tab[n] = 1;
        flag = true;
    }else{
        cake[n].cal = cake[n].half;
        tab[n] = n;
        index = n - 1;

        while(true){
            if(cake[index + 1].cal >= cake[index].cal){
                opt = index + 1;
            }else{
                opt = index;
            }

            if(tab[index] == opt){
                break;
            }else{
                cake[opt].cal = cake[opt].half;
                tab[index] = opt;
                index--;
            }
        }
    }

    if(flag == true){
        if(cake[1].cal <= cake[2].cal){
            tab[1] = 2;
        }else{
            tab[1] = 1;
        }
    }

    for(int i = 1;i <= n;i++){
        cout << tab[i] << ' ';
    }

    return 0;
}
