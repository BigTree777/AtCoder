#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, M;
    cin >> N >> M;

    int A[M+1], B[M+1];
    vector<int> G[N+1];
    set<int> S;
    for(int i = 1; i < M+1; i++){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
        S.insert(A[i]);
        S.insert(B[i]);
    }

    vector<int> nums(N+1, 0);
    for(int  s: S){
        if(G[s].size()==0) continue;
        int num = 0;
        for(int g: G[s]){
            if(g < s) num += 1;
        }
        nums[s] = num;
    }

    int ans = 0;
    for(int n: nums){
        if(n == 1) ans += 1;
    }
    cout << ans << endl;

    return 0;
}