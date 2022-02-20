#include<bits/stdc++.h>
using namespace std;

bool judge(string& S){
    bool pld;
    int S_half_size = floor(S.size() * 0.5);
    for(int i=0; i<S_half_size; i++){
        // cout << S[i] << endl;
        // cout << S.size() << endl;
        if(S[i]==S[S.size()-1-i]){
            pld = true;
            continue;
        }
        else{
            pld = false;
            break;
        }
    }
    return pld;
}

int main(){
    string S;
    cin >> S;
    bool pld = judge(S);
    if(pld){
        cout << "Yes" << endl;
        return 0;
    }

    deque<int> a_pos;
    int a_pos_int;
    string target_a = "a";
    int S_half_size = floor(S.size() * 0.5);

    for(int i=0; i<S_half_size; i++){
        if(S[i] == target_a[0]){
            a_pos.push_front(i);
        }
        else if(S[S.size()-1-i] == target_a[0]){
            a_pos.push_front(S.size()-1-i);
        }
    }
    sort(a_pos.begin(), a_pos.end(), std::greater<int>{});

    int before_a_pos_int = a_pos.front();
    a_pos.pop_front();
    if(before_a_pos_int!=S.size()-1){
        cout << "No" << endl;
        return 0;
    }
    int add_a = 1;
    int range = a_pos.size();
    for(int i=0; i<range; i++){
        a_pos_int = a_pos.front();
        a_pos.pop_front();
        if(a_pos_int-before_a_pos_int==-1) add_a++;
        else break;
        before_a_pos_int = a_pos_int;
    }
    for(int i=0; i<add_a; i++){
        S = target_a + S;
        if(judge(S)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}