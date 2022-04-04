#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll N;
    cin >> N;

    queue<ll> ans;
    for(ll i = 1; i * i <= N; i++){
        if(N % i == 0){
            ans.push(i);
            if(N != i * i) ans.push(N/i);
        }
    }
    ll size = ans.size();
    for(ll i = 0; i < size; i++){
        cout << ans.front() << endl;
        ans.pop();        
    }
    
    return 0;
}