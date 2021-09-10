#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include "general.hpp"
#include "special.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    //set up command line arguments
    //this will be n for problems 7, 9, and 10
    if (argc != 2)  // Expect 1 command-line argument
      {
        // Get the name of the executable file
        string executable_name = argv[0];

        cerr << "Error: Wrong number of input arguments." << endl;
        cerr << "Usage: " << executable_name << " <some integer> " << endl;

        // Exit program with non-zero return code to indicate a problem
        return 1;
      }
    
    int n = atoi(argv[1]);
    
    //Problem 2
    //setup for output file
    //set filename
    string filename = "u_x.txt";
    //create and open output file
    ofstream ofile;
    ofile.open(filename);
    //width and precision parameters
    int width = 12;
    int prec = 4;
    
    //get x and find u(x)
    double c = (1 - exp(-10));
    for (int i = 0; i < 100; i++){
        double x = i/100;
        double u = 1 - c*x - exp(-10*x);
        //output u and a to file:
        ofile << setw(width) << setprecision(prec) << scientific << x
              << setw(width) << setprecision(prec) << scientific << u
              << endl;
    }
    
    //close output file
    ofile.close();
    
    //Problem 7
    string filename1 = "v_x_" + to_string(n) + ".txt";
    //create and open output file
    ofstream ofile1;
    ofile1.open(filename1);
    
    //start measuring time for problem 10
    auto t1 = std::chrono::high_resolution_clock::now();
    
    //define x and g
    vector<double> x1;
    vector<double> g1;
    for(double i = 0; i < n+1; i++){
        x1.push_back(i/n);
        g1.push_back(100*exp(i/n)*pow(1.0/n, 2));
    }
    g1.back() = g1.back()+1;
    
    //call general to get v
    vector<double> a1(n-1, -1.0);
    vector<double> b1(n, 2.0);
    vector<double> c1(n-1, -1.0);
    vector<double> v1 = general(n, a1, b1, c1, g1);
    
    // Stop measuring time
    auto t2 = std::chrono::high_resolution_clock::now();
    // Calculate the elapsed time
    // We use chrono::duration<double>::count(), which by default returns duration in seconds
    double time_general = std::chrono::duration<double>(t2 - t1).count();
    
    //write v and x to a file
    for (int i = 0; i < n; i++){
        ofile1 << setw(width) << setprecision(prec) << scientific << x1[i]
              << setw(width) << setprecision(prec) << scientific << v1[i]
              << endl;
    }
    ofile1.close();
    
    //Problem 9
    //setup for output file
    //set filename
    string filename2 = "sv_x_" + to_string(n) + ".txt";
    //create and open output file
    ofstream ofile2;
    ofile2.open(filename2);
    
    //start measuring time for problem 10
    auto t3 = std::chrono::high_resolution_clock::now();
    
    //define x and g
    vector<double> x2;
    vector<double> g2;
    for(double i = 0; i < n+1; i++){
        x2.push_back(i/n);
        g2.push_back(100*exp(i/n)*pow(1.0/n, 2));
    }
    g2.back() = g2.back()+1;
    
    //call special to get v
    vector<double> v2 = special(n, g2);
    
    // Stop measuring time
    auto t4 = std::chrono::high_resolution_clock::now();
    // Calculate the elapsed time
    double time_special = std::chrono::duration<double>(t4 - t3).count();
    
    //write v and x to a file
    for (int i = 0; i < n; i++){
        ofile2 << setw(width) << setprecision(prec) << scientific << x2[i]
              << setw(width) << setprecision(prec) << scientific << v2[i]
              << endl;
    }
    ofile2.close();
    
    //Problem 10
    cout << n << " " << time_general << " " << time_special << "\n";
}

