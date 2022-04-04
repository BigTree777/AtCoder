#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool prime(ll N){
    for(ll i = 2; i * i <= N; i++){
        if(N % i == 0) return false;
    }
    return true;
}

int main(){
    ll N;
    cin >> N;

    vector<ll> ans;
    while(1){
        if(prime(N)){
            ans.push_back(N);
            break;
        }
        for(ll i = 2; i * i <= N; i++){
            if(N % i != 0) continue;
            if(prime(i)){
                ans.push_back(i);
                N /= i;
                break;
            }
        }
    }

    for(ll a: ans){
        cout << a << endl;
    }
    return 0;
}