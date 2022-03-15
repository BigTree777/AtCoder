#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    int h[N];
    for(int i = 0; i < N; i++) cin >> h[i];

    int dp[N];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    int one = 0, two = 0;
    for(int i = 2; i < N; i++){
        one = dp[i-1] + abs(h[i] - h[i-1]);
        two = dp[i-2] + abs(h[i] - h[i-2]);
        dp[i] = min(one, two);
    }
    cout << dp[N - 1] << endl;
    return 0;
}