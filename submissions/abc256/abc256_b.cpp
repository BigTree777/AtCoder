#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    
    deque<int> q;
    ull ans = 0;
    for(int i = 0; i < N; i++){
        q.push_back(0);
        for(int j = 0; j < q.size(); j++){
            q[j] += A[i];
        }
        while(q.front() > 3){
            q.pop_front();
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}