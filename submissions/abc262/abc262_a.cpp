#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int Y;
    cin >> Y;

    int y = Y % 4;
    if(y <= 1) y = 2 - y;
    else if(y == 3) y = 3;
    else y = 0;
    int ans = Y + y;
    cout << ans << endl;

    return 0;
}