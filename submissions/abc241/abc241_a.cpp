#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int a[10];
    for(int i = 0; i < 10; i++) cin >> a[i];

    int next = 0;
    int ans;
    for(int i = 0; i < 3; i++){
        ans = a[next];
        next = a[next];
    }
    cout << ans << endl;
    return 0;
}