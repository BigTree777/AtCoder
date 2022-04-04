#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int t = A * 60 * 60 + B * 60;
    int a = C * 60 * 60 + D * 60 + 1;
    if(t < a) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}