#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    vector<int> A[N];
    vector<int> vec(N, 0);
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        A[i] = vec;
        for(int j = 0; j < N; j++){
            A[i][j] = (int)s[j] - 48;
        }
    }

    vector<int> i_dif = {1, 1, 1, 0, 0, -1, -1, -1};
    vector<int> j_dif = {1, 0, -1, 1, -1, 1, 0, -1};
    vector<int> ans(N, 0);
    vector<int> tmp_ans;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < 8; k++){
                tmp_ans.clear();
                for(int l = 0; l < N; l++){
                    int i_pos = (i + i_dif[k] * l + N) % N;
                    int j_pos = (j + j_dif[k] * l + N) % N;
                    tmp_ans.push_back(A[i_pos][j_pos]);
                }
                assert(tmp_ans.size() == N);
                bool replace = true;
                for(int l = 0; l < N; l++){
                    if(ans[l] > tmp_ans[l]){
                        replace = false;
                        break;
                    }
                    else if(ans[l] < tmp_ans[l]){
                        replace = true;
                        break;
                    }
                    else continue;
                }
                if(replace) ans = tmp_ans;
            }
        }
    }
    for(int a: ans) cout << a;
    cout << endl;
    return 0;
}