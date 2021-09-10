# fys4150

Repository for FYS4150 (Computational Physics) at UiO.

## Project 1:

To run the project1 c++ code, you need the headers general.hpp and special.hpp. Compiling and running project1.cpp generates files "u_x.txt", "v_x_n.txt", and "sv_x_n.txt" where n is an integer passed at the command line, like so:

$ ./project1.exe n

It also outputs the choice of n, the time it took to run the general algorithm, and the time it took to run the special algorithm. This was used to generate the file "timing.txt", which is included in this repo for convenience since it takes a long time to make. It was generated by running project1 for a given value of n and appending the result to a .txt file:

$ ./project1.exe n >> timing.txt

This was done 5 times for each value of n to ensure a spread of results. 

The Jupyter notebook project_1_final.ipynb included in this repo generates the plots and tables used in the report. To run it, first compile and run the c++ code to generate .txt files for n = 10, 100, 1000, 10.000, 100.000, 1.000.000, and 10.000.000, which takes a minute or two. You will also need to generate or download timing.txt. As long as the resulting files are in the same directory as the notebook, it should run; if you have problems you may need to go in and specify the filepaths.
