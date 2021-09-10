# fys4150

Repository for FYS4150 (Computational Physics) at UiO.

Project 1:

To run the project1 c++ code, you need the headers general.hpp and special.hpp. Compiling and running project1.cpp generates files "u_x.txt", "v_x_n.txt", and "sv_x_n.txt" where n is an integer passed at the command line, like so:

$ ./project1.exe n

It also outputs the choice of n, the time it took to run the general algorithm, and the time it took to run the special algorithm. Running project1 for differing values of n will generate all the .txt files in this repo, except for "timing.txt". That was generated by running project1 5 times for each value of n, and appending the output to a .txt file:

$ ./project1.exe n >> timing.txt

The Jupyter notebook project_1_final.ipynb included in this repo generates the plots and tables used in the report. To run it, first compile and run the c++ code to generate .txt files (or download the files included here). As long as the files are in the same directory as the notebook, it should run; if you have problems you may need to go in and specify the filepaths.
