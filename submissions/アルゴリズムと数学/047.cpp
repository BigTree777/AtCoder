#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, M;
    cin >> N >> M;

    int A[M+1], B[M+1];
    vector<int> G[N+1];
    for(int i = 0; i < M; i++){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    vector<int> color(N+1, -1);

    queue<int> q;
    bool err = false;
    for(uint i = 1; i < color.size(); i++){
        if(color[i] != -1) continue;
        q.push(i);
        color[i] = 0;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(uint j = 0; j < G[now].size(); j++){
                int g = G[now][j];
                if(color[g] == -1){
                    color[g] = (color[now] + 1)%2;
                    q.push(g);
                }
                else if(color[now] == color[g]){
                    err = true;
                    break;
                }
            }
            if(err) break;
        }
        if(err) break;
    }
    if(err) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}