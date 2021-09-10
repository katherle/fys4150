#ifndef special_hpp
#define special_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

vector<double> special(int n, vector<double> g){
    //goes through the special algorithm
    //to solve for v
    
    //forward substitution
    vector<double> b_tilde;
    vector<double> g_tilde;
    b_tilde.push_back(2);
    g_tilde.push_back(g[0]);
    for(vector<double>::size_type i = 1; i != g.size(); i++){
        double d = 1.0/b_tilde[i-1];
        b_tilde.push_back(2 - d);
        g_tilde.push_back(g[i] + d*g[i-1]);
        }
    
    //back substitution
    vector<double> v;
    v.push_back(g_tilde.back()/b_tilde.back());
    for(vector<double>::size_type i = 1; i != g.size(); i++){
        v.push_back((g_tilde[i] + v[i-1])/b_tilde[i]);
    }
    
    //reverse order of v
    reverse(v.begin(),v.end());
    
    return v;
}

#endif
