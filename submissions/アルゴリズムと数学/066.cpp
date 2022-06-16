#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, K;
    cin >> N >> K;

    ull ans = 0;
    for(int i = 1; i < N+1; i++){
        for(int j = max(1, i-K+1); j < min(N+1, i+K); j++){
            for(int k = max(1, i-K+1); k < min(N+1, i+K); k++){
                if(abs(j-k) < K) ans += 1;
            }
        }
    }
    ans = pow(N, 3) - ans;
    cout << ans << endl;
    return 0;
}