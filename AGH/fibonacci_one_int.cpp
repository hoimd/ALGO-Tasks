#include<iostream>
#define p 100000000

int main(){
    uint64_t x = 1;
    while(!((x / p) % 10)){
        std::cout << x % p << std::endl;
        x = ((x % p) * p * 10) + (x % p + x / (p * 10));
    }
    return 0;
}