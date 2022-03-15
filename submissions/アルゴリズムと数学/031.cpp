#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 1; i < n+1; i++) cin >> a[i];

    ll dp1[n+1], dp2[n+1];
    dp1[0] = 0; // 勉強した場合
    dp2[0] = 0; // 勉強しない場合
    for(int i = 1; i < n+1; i++){
        dp1[i] = dp2[i-1] + a[i]; // 前々日のmax + 当日勉強
        dp2[i] = max(dp1[i-1], dp2[i-1]); // 前日のmax = 当日勉強しない
    }
    cout << max(dp1[n], dp2[n]) << endl;

    return 0;
}