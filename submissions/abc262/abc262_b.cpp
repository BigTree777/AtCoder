#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> G[N+1];
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans = 0;
    queue<int> Qb, Qc;
    for(int i = 1; i < N+1; i++){
        // i == a
        if(G[i].size() == 0) continue;
        for(int g: G[i]){
            if(i < g) Qb.push(g); // Add b in Q
        }
        int q;
        while(Qb.size() != 0){
            q = Qb.front(); // b
            Qb.pop();
            for(int g: G[q]){
                if(q < g) Qc.push(g); // Add c in Q
            }
        }
        while(Qc.size() != 0){
            q = Qc.front(); // c
            Qc.pop();
            for(int g: G[q]){
                if(i == g){ // Judge if c link with a
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}