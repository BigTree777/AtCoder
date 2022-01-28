#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    map<int, deque<int>> A;
    vector<int> vec(N+1, 1);
    int a;
    for(int i=0; i<(4*N-1); i++){
        cin >> a;
        A[a].push_back(a);
        if(A[a].size()==4) vec[a] = 0;
        // cout << i << endl;
    }
    int ans;
    for(int i=1; i<N+1; i++){
        if(vec[i]==1){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}