#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M, Q;
    cin >> N >> M >> Q;

    map<pair<int, int>, int> G;
    int a, b, c;
    pair<int, int> pair_ab;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        pair_ab = make_pair(a, b);
        G[pair_ab] = c;
    }

    int u, v, w;
    pair<int, int> pair_uv;
    vector<string> ans;
    for(int i=0; i<Q; i++){
        pair_uv = make_pair(u, v);
        if(!G.count(pair_uv)) ;
    }

    return 0;
}