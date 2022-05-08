#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, Q;
    cin >> N >> Q;

    int x[Q];
    for(int i = 0; i < Q; i++) cin >> x[i];

    vector<int> ans;
    for(int i = 0; i <= N; i++) ans.push_back(i);

    map<int, int> ma;
    for(int i = 1; i <= N; i++) ma[i] = i;
    for(int i = 0; i < Q; i++) {
        int tmp;
        tmp = ans[ma[x[i]]];
        if(ma[x[i]] == N){
            ans[N] = ans[N-1];
            ans[N-1] = tmp;
            ma[tmp] = N;
            ma[x[i]] = N - 1;
        }
        else{
            ans[ma[x[i]]] = ans[ma[x[i]]+1];
            ans[ma[x[i]]+1] = tmp;
            ma[ans[ma[x[i]]]] = ma[x[i]];
            ma[ans[ma[x[i]]+1]] = ma[x[i]] + 1;
        }
    }

    for(int i = 1; i <= N; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}