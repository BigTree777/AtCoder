#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    ll L, W;
    cin >> N >> L >> W;
    ll a, start = 0;
    ll ans = 0;
    ll A[N];

    for(ll i=0; i<N; i++){
        cin >> A[i];
        if(a > start){
            ans += ceil((double)(a - start) / (double)W);
        }
        start = a + W + 1;
    }

    if(L >= start){
        ans += ceil((double)(L - start) / (double)W);
    }

    if(A[0]>0){
        ans++;
    }
    cout << ans << endl;
    return 0;
}