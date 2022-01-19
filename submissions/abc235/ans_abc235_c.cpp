/// source_code: https://atcoder.jp/contests/abc235/submissions/28554382

#include<bits/stdc++.h>
using namespace std;

int n, m, a, x, y;
map<int, vector<int>> p; // int -> vectorの連想配列

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a;
        p[a].push_back(i);
    }
    while(m--){
        cin >> x >> y;
        cout << (p[x].size() >= y ? p[x][y-1] : -1) << endl;
    }
}
