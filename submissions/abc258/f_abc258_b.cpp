#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    vector<int> A[N];
    vector<int> vec(N, 0);
    int _max = 0;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        A[i] = vec;
        for(int j = 0; j < N; j++){
            A[i][j] = (int)s[j] - 48;
            if(_max < A[i][j]){
                _max = A[i][j];
            }
        }
    }

    queue<pair<int, int>> que;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i][j] == _max){
                pair<int, int> pos = make_pair(i, j);
                que.push(pos);
            }
        }
    }

    queue<vector<pair<int, int>>> candidate;
    while(que.size() != 0){
        pair<int, int> p = que.front();
        que.pop();
        int next_max = 0;
        pair<int, int> next_p;
        if(next_max < A[p.first-1][p.second]){
            next_p = make_pair(p.first-1, p.second);
        }
        if(next_max < A[p.first-1][p.second-1]){
            next_p = make_pair(p.first-1, p.second-1);
        }
        if(next_max < A[p.first-1][p.second+1]){
            next_p = make_pair(p.first-1, p.second+1);
        }
        if(next_max < A[p.first][p.second-1]){
            next_p = make_pair(p.first, p.second-1);
        }
        if(next_max < A[p.first][p.second+1]){
            next_p = make_pair(p.first, p.second+1);
        }
        if(next_max < A[p.first+1][p.second]){
            next_p = make_pair(p.first+1, p.second);
        }
        if(next_max < A[p.first+1][p.second-1]){
            next_p = make_pair(p.first+1, p.second-1);
        }
        if(next_max < A[p.first+1][p.second+1]){
            next_p = make_pair(p.first+1, p.second+1);
        }
        vector<pair<int, int>> v = {p, next_p};
        candidate.push(v);
    }

    vector<int> ans(N, 0);
    vector<int> tmp_ans(N, 0);
    while(candidate.size() != 0){
        vector<pair<int, int>> vec_candi = candidate.front();
        candidate.pop();
        tmp_ans.clear();
        int i_interval = vec_candi[1].first - vec_candi[0].first;
        int j_interval = vec_candi[1].second - vec_candi[0].second;
        tmp_ans.push_back(A[vec_candi[0].first][vec_candi[0].second]);
        if(ans[0] > tmp_ans[0]) continue;
        tmp_ans.push_back(A[vec_candi[1].first][vec_candi[1].second]);
        if(ans[1] > tmp_ans[1]) continue;
        bool success = false;
        for(int i = 1; i <= N-2; i++){
            tmp_ans.push_back(A[vec_candi[1].first + i_interval][vec_candi[1].second]+j_interval);
            if(ans[i+1] > tmp_ans[i+1]) break;
        }
        if(success){
            ans = tmp_ans;
        }
    }
    for(int a: ans){
        cout << a << endl;
    }
    return 0;
}