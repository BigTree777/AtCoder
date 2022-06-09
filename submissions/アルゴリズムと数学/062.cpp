#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ull N, K;
    cin >> N >> K;

    vector<uint> A(N+1, 0);
    for(int i = 1; i < N+1; i++) cin >> A[i];

    uint now = 1;
    uint before = 0;
    set<uint> s;
    s.insert(now);
    uint before_size = 0;
    // 繰り返し部分の始点と終点を探す
    while(s.size() != before_size){
        before = now;
        now = A[now];
        before_size = s.size();
        s.insert(now);
    }
    // 繰り返し部分を抜き出す
    uint start_loop = now;
    uint end_loop = before;
    vector<uint> vec_loop;
    vec_loop.push_back(start_loop);
    while(end_loop != now){
        now = A[now];
        vec_loop.push_back(now);
    }
    // main
    now = 1;
    uint ans = 0;
    ull count = 0;
    while(count < K){
        count += 1;
        now = A[now];
        if(now == start_loop) break;
    }
    if(count == K){
        ans = now;
        cout << ans << endl;
        return 0;
    }
    ull rest = K - count;
    rest = rest % vec_loop.size();
    ans = vec_loop[rest];
    cout << ans << endl;
    return 0;
}