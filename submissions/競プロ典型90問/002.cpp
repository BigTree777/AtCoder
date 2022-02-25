// 長さが小さいものから順に累積的に算出
// 最終的に求めたい長さのものをバブルソート -> TLE

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    if(N%2!=0){
        cout << "" << endl;
        return 0;
    }

    map<int, vector<string>> ans;
    vector<vector<int>> vec_sort;
    int max_div = N * 0.5;
    int div_1, div_2;

    for(int i=2; i<N+1; i+=2){
        // cout << "**************" << i << endl;
        vector<string> vec;
        ans[i] = vec;
        if(i==2){
            ans[i].push_back("()");
            continue;
        }
        // (+S+)
        for(int j=0; j<ans[i-2].size(); j++){
            ans[i].push_back((string)"(" + ans[i-2][j] + (string)")");
        }
        // S+T
        for(int j=1; j<max_div; j++){
            div_1 = 2 * j;
            div_2 = i - div_1;
            if(div_1 > div_2) break;
            // cout << div_1 << " - " << div_2 << endl;
            for(int k=0; k<ans[div_1].size(); k++){
                for(int l=0; l<ans[div_2].size(); l++){
                    if(find(ans[i].begin(), ans[i].end(), ans[div_1][k] + ans[div_2][l])==ans[i].end())
                        ans[i].push_back(ans[div_1][k] + ans[div_2][l]);
                    if((ans[div_1][k] != ans[div_2][l]) && (div_1 != div_2)){
                        if(find(ans[i].begin(), ans[i].end(), ans[div_2][l] + ans[div_1][k])==ans[i].end())
                            ans[i].push_back(ans[div_2][l] + ans[div_1][k]);
                    }
                }
            }
        }
    }
    // sort
    vector<int> v;
    for(int j=0; j<ans[N].size(); j++){
        for(int k=0; k<ans[N][j].size(); k++){
            if(ans[N][j][k]==')'){
                v.push_back(k);
            }
        }
        vec_sort.push_back(v);
        v.clear();
    }
    int end = 0;
    string str;
    while(vec_sort.size()-1!=end){
        for(int j=vec_sort.size()-1; j>end; j--){
            for(int k=0; k<N*0.5; k++){
                if(vec_sort[j][k] == vec_sort[j-1][k]) continue;
                else if(vec_sort[j][k] > vec_sort[j-1][k]){
                    str = ans[N][j];
                    ans[N][j] = ans[N][j-1];
                    ans[N][j-1] = str;
                    v = vec_sort[j];
                    vec_sort[j] = vec_sort[j-1];
                    vec_sort[j-1] = v;
                    break;
                }
                else break;
            }
        }
        end += 1;
    }
    for(int i=0; i<ans[N].size(); i++){
        cout << ans[N][i] << endl;
        // cout << i << ": " << ans[N][i] << endl;
    }
    return 0;
}