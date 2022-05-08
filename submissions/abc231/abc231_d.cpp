#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

uint find(vector<uint>& vec, uint x){
    if(vec[x] == x){
        return x;
    }
    else{
        vec[x] = find(vec, vec[x]);
        return vec[x];
    }
}

bool unite(vector<uint>& vec, uint x, uint y){
    x = find(vec, x);
    y = find(vec, y);
    if(x == y) return false;
    
    vec[x] = y;
    return true;
}

int main(){
    uint N, M;
    cin >> N >> M;

    uint A[M], B[M];
    for(uint i = 0; i < M; i++) cin >> A[i] >> B[i];

    vector<uint> G[N+1];
    for(uint i = 0; i < M; i++){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    vector<uint> par(N+1, 0);
    for(uint i = 0; i < N+1; i++) par[i] = i;

    bool no = false;
    for(uint i = 0; i < M; i++){
        if((G[A[i]].size() == 3) || (G[B[i]].size() == 3)){
            no = true;
        }
        if(!unite(par, A[i], B[i])){
            no = true;
        }
        if(no){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}