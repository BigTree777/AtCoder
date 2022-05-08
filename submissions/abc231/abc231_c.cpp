#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    uint N, Q;
    cin >> N >> Q;

    vector<ull> A(N, 0);
    map<ull, ull> m;
    for(uint i = 0; i < N; i++){
        cin >> A[i];
        if(m.find(A[i]) != m.end()) m[A[i]] += 1;
        else m[A[i]] = 1;
    }

    for(map<ull, ull>::reverse_iterator ritr = m.rbegin(); ritr != m.rend(); ritr++){
        map<ull, ull>::reverse_iterator next_ritr = next(ritr);
        if(next_ritr == m.rend()) continue;
        m[next_ritr->first] += m[ritr->first];
    }

    uint x[Q];
    for(uint i = 0; i < Q; i++) cin >> x[i];

    ull ans;
    for(uint i = 0; i < Q; i++){
        if(m.find(x[i]) != m.end())  ans = m[x[i]];
        else if(m.upper_bound(x[i]) != m.end()) ans = m.upper_bound(x[i])->second;
        else ans = 0;
        cout << ans << endl;
    }

    return 0;
}