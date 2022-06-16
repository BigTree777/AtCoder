#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ull N;
    cin >> N;

    if(N % 4 == 1) cout << 2 << endl;
    else if(N % 4 == 2) cout << 4 << endl;
    else if(N % 4 == 3) cout << 8 << endl;
    else if(N % 4 == 0) cout << 6 << endl;

    return 0;
}