#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
priority_queue<
    pair<int, int>, // 
    vector<pair<int, int>>, 
    greater<pair<int, int>>> Q;

void dijkstra(int K, int dist[], bool used[], vector<pair<int, int>>* G){
    // Init
	for (int i = 0; i < K; i++) dist[i] = INT_MAX;
	for (int i = 0; i < K; i++) used[i] = false;
	Q.push(make_pair(0, 0)); // ここでdist[0] = 0 にはしないことに注意！

	while (!Q.empty()) {
		int pos = Q.top().second; Q.pop();
		if (used[pos]) continue;
		used[pos] = true;
        cout << pos;
		for (pair<int, int> g : G[pos]) {
			int to = g.first, cost = dist[pos] + g.second; // 十の位以上の和＋余り
			if (pos == 0) cost = g.second; // dist[-1]は存在しない
			if (dist[to] > cost) {
				dist[to] = cost; // Update dist
				Q.push(make_pair(dist[to], to));
			}
		}
        if(!Q.empty()) cout << "->" << endl;
	}

}

int main(){
    int K;
    cin >> K;

    vector<pair<int, int>> G[K];
    for(int i = 0; i < K; i++){
        for(int j = 0; j < 10; j++){
            if(i == 0 && j == 0) continue;
            G[i].push_back(make_pair((i * 10 + j) % K, j)); //各桁の総和の全パターンは10倍までで求まる 
        }
    }

    int dist[K];
    bool used[K];
    dijkstra(K, dist, used, G);

    cout << dist[0] << endl;
    return 0;
}