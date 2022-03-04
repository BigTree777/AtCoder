// 単純にやるとTLE

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int Q;
    cin >> Q;

    int c[Q], x[Q], k[Q];
    for(int i = 0; i < Q; i++){
        cin >> c[i];
        if(c[i] == 1){
            cin >> x[i];
            k[i] = 0;
        }
        else cin >> x[i] >> k[i];
    }

    vector<ull> A;
    vector<vector<ull>> div_A(18, vector<ull>());
    int count;
    int idx;
    ull ans;
    vector<ull>::iterator start, end;
    for(int i = 0; i < Q; i++){
        if(c[i] == 1){
            A.push_back(x[i]);
            sort(A.begin(), A.end());
            for(int j = 0; j < 18; j++){
                if(x[i] < pow(10, j+1)){
                    div_A[j].push_back(x[i]);
                    break;
                }
            }
        }
        else if(c[i] == 2){
            count = 0;
            for(int j = 0; j < 18; j++){
                if(x[i] < pow(10, j+1)){
                    start = div_A[j].begin();
                    end = div_A[j].end();
                    idx = j;
                    break;
                }
            }
            while((idx < 18) && (-1 < idx)){
                for(vector<ull>::iterator it = end - 1; it != start - 1; it--){
                    if(*it <= x[i]){
                        count += 1;
                        ans = *it;
                        if(count == k[i]) break;
                    }
                    else if(*it > x[i]) break;
                }
                if(count != k[i]){
                    idx -= 1;
                    start = div_A[idx].begin();
                    end = div_A[idx].end();
                    continue;
                }
                else break;
            }
            if(count == k[i]) cout << ans << endl;
            else cout << -1 << endl;
        }
        else if(c[i] == 3){
            count = 0;
            for(int j = 17; j > -1; j--){
                if(x[i] >= pow(10, j)){
                    start = div_A[j].begin();
                    end = div_A[j].end();
                    idx = j;
                    break;
                }
            }
            while((idx < 18) && (-1 < idx)){
                for(vector<ull>::iterator it = start; it != end; it++){
                    if(*it >= x[i]){
                        count += 1;
                        ans = *it;
                        if(count == k[i]) break;
                    }
                    else if(*it > x[i]) break;
                }
                if(count != k[i]){
                    idx += 1;
                    start = div_A[idx].begin();
                    end = div_A[idx].end();
                    continue;
                }
                else break;
            }
            if(count == k[i]) cout << ans << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}