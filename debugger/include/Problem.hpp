/// Make problems
///

#ifndef _PROBLEM_HPP_
#define _PROBLEM_HPP_


#include<stdio.h>
#include<limits.h>
#include<iostream>
#include<random>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

struct Edge{
    int start;
    int end;
    int cost;
};
using Graph = std::vector<Edge>;

class Problem{
public:   
    // Common
    int int_len; 
    bool duplex = false;

    // Graph
    Graph G;
    bool make_graph();

    // Search
    // Variable
    int search_target;
    int search_ans;
    std::map<int, std::vector<int>> map_search_problem; // answer index + problem vector
    std::vector<int> vec_shuffle_iota;
    std::vector<int> vec_iota;
    // Function
    bool make_vec_iota();
    bool make_vec_shuffle_iota();
    bool make_map_search_problem();
    bool check_sort_problem(std::vector<int> &vec) {return false;};
    bool check_search_problem(int &ans);
    void cout_comment(bool b);

    //Simple Sort

    // Constructor
    Problem(int N, bool dplx=false, int P=(int)INT_MIN){
        std::mt19937_64 new_engine(seed_gen());
        engine = new_engine;
        int_len = N;
        duplex = dplx;
        if(P!=INT_MIN){
            search_target = P;
        }
    }
private:
    std::random_device seed_gen;
    std::mt19937_64 engine;
};

#endif