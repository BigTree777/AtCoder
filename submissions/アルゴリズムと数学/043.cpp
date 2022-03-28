#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;


void dfs(vector<bool>& visited, vector<int> G[], int pos){
    visited[pos] = true;
    for(int i: G[pos]){
        if(visited[i] == false) dfs(visited, G, i);
    }
}
    
int main(){
    int N, M;
    cin >> N >> M;

    int A[M+1], B[M+1];
    vector<int> G[N+1];
    for(int i = 1; i < M+1; i++){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    vector<bool> visited(N+1, false);
    visited[0] = true;
    dfs(visited, G, 1);

    bool ans = true;
    for(bool v: visited){
        if(!v) ans = false;
    }
    if(ans) cout << "The graph is connected." << endl;
    else cout << "The graph is not connected." << endl;

    return 0;
}