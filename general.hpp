#ifndef general_hpp
#define general_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

vector<double> general(int n, vector<double> a, vector<double> b,
                        vector<double>c, vector<double> g){
    //take number of steps and g as inputs and solve for v
    //A is the tridiagonal matrix with subdiagonal a, diagonal b, and superdiagonal c
    
    //forward substitution
    vector<double> b_tilde;
    vector<double> g_tilde;
    b_tilde.push_back(b[0]);
    g_tilde.push_back(g[0]);
    for(vector<double>::size_type i = 1; i != b.size(); i++){
        double d = a[i]/b_tilde[i-1];
        b_tilde.push_back(b[i] - d*c[i-1]);
        g_tilde.push_back(g[i] - d*g[i-1]);
        }
    
    //back substitution
    vector<double> v;
    v.push_back(g_tilde.back()/b_tilde.back());
    for(vector<double>::size_type i = 1; i != b.size(); i++){
        v.push_back((g_tilde[i] - c[i]*v[i-1])/b_tilde[i]);
    }
    //reverse order of v because I didn't know how to append onto the front of a vector
    //instead of onto the back
    reverse(v.begin(),v.end());
    
    return v;
}

#endif
