// source: https://github.com/E869120/kyopro_educational_90/blob/main/sol/003.cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Input
int N;
int A[1 << 18], B[1 << 18];

// Graph
const int INF = (1 << 29);
vector<int> G[1 << 18];
int dist[1 << 18];

void getdist(int start) {
	// Find the shortest distance by BFS
	for (int i = 1; i <= N; i++) dist[i] = INF;

	queue<int> Q;
	Q.push(start);
	dist[start] = 0;

	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		for (int to : G[pos]) {
			if (dist[to] == INF) {
				dist[to] = dist[pos] + 1;
				Q.push(to);
			}
		}
	}
}

int main() {
	// Step #1. Input
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	// Step #2. Find the shortest distance from vertex 1
	// maxid1: The vertex that is the farthest from vertex 1
	getdist(1);
	int maxn1 = -1, maxid1 = -1;
	for (int i = 1; i <= N; i++) {
		if (maxn1 < dist[i]) {
			maxn1 = dist[i];
			maxid1 = i;
		}
	}

	// Step #3. Find the shortest distance from vertex maxid
	// maxn2: The diamiter of this tree
	getdist(maxid1);
	int maxn2 = -1;
	for (int i = 1; i <= N; i++) {
		maxn2 = max(maxn2, dist[i]);
	}

	// Step #4. Output
	cout << maxn2 + 1 << endl;
	return 0;
}