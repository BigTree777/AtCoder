#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int a, b;
    cin >> a >> b;

    if(abs(a-b)==1) cout << "Yes" << endl;
    else if(( a == 1 ) && (b == 10)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}