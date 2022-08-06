#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void dfs(vector<ll>& vec, ll now, ll N, ll M){
    vec.push_back(now);
    if(vec.size() == N){
        for(ll v: vec) cout << v << " ";
        cout << endl;
        vec.erase(vec.end() - 1);
    }
    else{
        for(ll j = now + 1; j <= M - (N - vec.size()) + 1; j++){
            dfs(vec, j, N, M);
        }
        vec.erase(vec.end() - 1);
    }
}

int main(){
    ll N, M;
    cin >> N >> M;

    vector<ll> vec;
    for(ll i = 1; i <= M - N + 1; i++) dfs(vec, i, N, M);

    return 0;
}