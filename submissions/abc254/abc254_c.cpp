#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    map<int, vector<int>> m;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        m[a[i]].push_back(i);
    }

    vector<int> correct(a.size());
    copy(a.begin(), a.end(), correct.begin());
    sort(correct.begin(), correct.end());

    vector<int> vPos;
    for(int i = 0; i < (int)correct.size() - K; i++){
        vPos = m[correct[i]];
        bool exist = false;
        for(int j = 0; j < (int)vPos.size(); j++){
            int pos = vPos[j];
            if(abs(pos - i) % K == 0){
                vPos.erase(vPos.begin() + j);
                exist = true;
                break;
            }
        }
        if(!exist){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}