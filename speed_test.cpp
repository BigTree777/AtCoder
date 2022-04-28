#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int a = 0;
    int b = 1;
    int c;
    cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << endl;
    for(uint i = 0; i < 10; i++){
        clock_t start = clock();
        for(uint j = 0; j < 1E9; j++){
            c = a + b;
        }
        clock_t end = clock();
        double t = (double)(end - start) / CLOCKS_PER_SEC;
        cout << i << ": "  << t << " [s]" << endl;
    }
    
    return 0;
}