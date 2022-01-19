// ans_abc_235_d.cppを元に作成

#include<bits/stdc++.h>
using namespace std;
int top;

int op_1(int &a, int x, int count, vector<int> &vec_count){
    long long op1 = (long long)x * (long long)a;
    if(op1<top && vec_count[op1]==-1){
        vec_count[op1] = count + 1;
        return op1;
    }
    else return x;
}

int op_2(int x, int count, vector<int> &vec_count){
    if(x<10 || x%10==0) return x;
    int op2 = x;
    string str_op2;
    str_op2 = to_string(op2);
    str_op2 = str_op2.substr(str_op2.size()-1, 1) \
                + str_op2.substr(0, str_op2.size()-1);
    op2 = stoi(str_op2);
    if(op2<top && vec_count[op2]==-1){
        vec_count[op2] = count + 1;
        return op2;
    }
    else return x;
}

int main(){
    int a, N;
    cin >> a >> N;

    // Set top
    top = 1;
    while(top <= N) top *= 10;

    // index: x
    // content: count
    vector<int> vec_count(top+1, -1);
    vec_count[1] = 0;

    deque<int> x_deque(1, 1);
    int x, count = 1, op1 = 1, op2 = 1;    
    while(x_deque.size()){
        x = *(x_deque.begin());
        x_deque.pop_front();
        count = vec_count[x];

        op1 = op_1(a, x, count, vec_count);
        if(x!=op1) x_deque.push_back(op1);

        op2 = op_2(x, count, vec_count);
        if(x!=op2) x_deque.push_back(op2);
    }
    cout << vec_count[N] << endl;
}