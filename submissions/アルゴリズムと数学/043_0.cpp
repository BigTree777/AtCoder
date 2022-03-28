#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
    
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

    stack<int> s;
    s.push(1);
    visited[1] = true;
    while(!s.empty()){
        int now = s.top();
        bool b = true;
        for(int i = 0; i < G[now].size(); i++){
            int g = G[now][i];
            if(visited[g] == false){
                s.push(g);
                visited[g] = true;
                b = false;
                G[now].erase(G[now].begin() + i);
                break;
            }
        }
        if(b) s.pop();
    }

    bool ans = true;
    for(bool v: visited){
        if(!v) ans = false;
    }
    if(ans) cout << "The graph is connected." << endl;
    else cout << "The graph is not connected." << endl;

    return 0;
}