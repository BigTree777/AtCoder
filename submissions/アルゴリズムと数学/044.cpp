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

    vector<int> dist(N+1, -1);

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int g: G[now]){
            if(dist[g] == -1){
                q.push(g);
                dist[g] = dist[now] + 1;
            }
        }
    }
    for(int i = 1; i < dist.size(); i++){
        cout << dist[i] << endl;
    }

    return 0;
}