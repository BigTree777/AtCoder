#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    map<string, int> s_list;
    string station;
    for(int i=0; i<N; i++){
        cin >> station;
        s_list[station] = i;
    }
    vector<string> ans_list(N, "No");
    for(int i=0; i<M; i++){
        cin >> station;
        if(s_list.count(station)==1){
            ans_list[s_list[station]] = "Yes";
        }
    }
    for(string ans: ans_list){
        cout << ans << endl;
    }
    return 0;
}