// 単純に1つの配列内で木構造を再現しようとする -> 1つのノードにつながる複数のノードを表現できない
// unionfindを利用して表記しようとする -> パスの長さが消える

// Gを二重配列で作成
// 頂点1を除くすべての頂点について頂点1からの距離を算出する -> BFS(?)を利用
// 最長の位置にいる頂点のIDを取得（max_id） -> 木における端に移動
// 頂点max_idを除くすべての頂点について頂点max_idからの距離を求め，最大値を取得 -> 端から端までの距離
// これに1を足したのが答え
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int* BFS(vector<vector<int>> G, int* dist, int N, int start) {
	// Find the shortest distance from start by BFS
    // G: Graph
    // dist: index->[start point], value->[shortest distance]
    // N: Number of node
    // start: target

    // return dist

	for (int i = 1; i <= N; i++) dist[i] = INT_MAX;

	queue<int> Q;
	Q.push(start);
	dist[start] = 0; // Init

	while (!Q.empty()) {
		int pos = Q.front();
        Q.pop();
		for (int to : G[pos]) {
			if (dist[to] == INT_MAX) {
				dist[to] = dist[pos] + 1; // distance from start
				Q.push(to);
			}
		}
	}
    return dist;
}

int main(){
    int N, A, B;
    cin >> N;

    vector<vector<int>>  G(N, vector<int>());
    for(int i = 0; i < N; i++){
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    int* dist;
    dist = BFS(G, dist, N, 1);

    int max_dist = -1, max_id = -1;
    for(int i = 0; i < N; i++){
        max_dist = max(max_dist, dist[i]);
        if(dist[i]==max_dist) max_id = i;
    }

    dist = BFS(G, dist, N, max_id);
    int ans = -1;
    for(int i = 0; i < N; i++){
        ans = max(ans, dist[i]);
    }

    cout << ans + 1 << endl;
    return 0;
}

// int find(int root[], int i){
//     if(root[i]==i){
//         return i;
//     }
//     else{
//         return find(root, root[i]);
//     }
// }

// int size(int root[], int x){

// }

// int main(){
//     int N;
//     cin >> N;
//     int A[N], B[N];
//     for(int i=0; i<N; i++) cin >> A[i] >> B[i];

//     int root[N];
//     for(int i=0; i<N; i++) root[i] = i;

//     int a, b;
//     for(int i=0; i<N; i++){
//         a = find(root, A[i]);
//         b = find(root, B[i]);
//         if(a!=b){
//             root[max(a, b)] = min(a, b);
//         }
//     }
     
//     int ans;
//     for(int i=N-1; i>0; i--){
//         ans = max(ans, );
//     }


    
//     return 0;
// }