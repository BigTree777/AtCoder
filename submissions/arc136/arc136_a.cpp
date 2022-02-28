// 辞書順最小 -> 
// 長さは極力短く
// op1 -> convert A to BB
// op2 -> convert BB to A
// op1 + op2 -> Aを左にずらすことが可能
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    string S;
    cin >> S; // A + B + C

    string ans, buffer;
    int b_cnt = 0;
    int a_size;
    bool w = false;
    for(int i = 0; i < N; i++){
        // cout << ans << " : " << buffer << endl;
        if(S[i] == 'A'){
            if(b_cnt == 1){
                buffer.erase(buffer.end() - 1, buffer.end());
                buffer += "AB";
                continue;
            }
            else{
                buffer += 'A';
                b_cnt = 0;
            }
        }
        else if(S[i] == 'B'){
            b_cnt += 1;
            if(b_cnt == 2){
                buffer.erase(buffer.end() - 1, buffer.end());
                buffer += 'A';
                b_cnt = 0;
            }
            else{
                buffer += 'B';
                continue;
            }
        }
        else{
            buffer += S[i];
            b_cnt = 0;
        }
        ans += buffer;
        buffer.clear();
    }
    if(!buffer.empty()) ans += buffer;
    cout << ans << endl; 

    return 0;
}