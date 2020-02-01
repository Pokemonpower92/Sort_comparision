/*
    C++ protocol for testing the time to sort multiple input sizes for
    generic sorting algorithms.

    Sorting times for three differing arrays of random numbers are averaged
    for each input size.

    This averaged sorting time is stored in a file (for each algorithm) like so:

    /benchmarking/merge_cpp.txt:
      input_size_1_time input_size_2_time input_size_3_time ...


    ##TODO-
      - Implement a quicksort in sorting.hpp
*/

#include "sorting.hpp"
#include <iostream>
#include <cstdio>
#include <chrono>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char** argv){

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    vector<double> stl_times;
    vector<double> merge_times;
    vector<double> insertion_times;
    //vector<double> quick_times;

    for(int i = 1; i != 151; i++){

      // Average for each sort type.
      chrono::duration<double> stl_average;
      chrono::duration<double> merge_average;
      chrono::duration<double> insertion_average;
      //chrono::duration<double> quick_average;

      printf("Generating file: %d\n", i);
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      // For each file for that size we need to add the runtime for each random
      // input to the running total of runtime for that sort.
      for(int j = 1; j != 2; j++){
        ifstream fin;
        char infile[100];
        int num;
        vector<int> data;
        vector<int> to_sort;

        sprintf(infile, "./io/rand%d%d.txt", i, j);

        fin.open(infile);
        if(fin.fail()){
          perror(infile);
        }

        // Read in the data.
        while(fin >>  num){
            data.push_back(num);
        }

        to_sort = data;
        fin.close();

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Done reading the input file. Time to run each
        // sorting implementation on the data.

        // For merge.
        chrono::time_point<chrono::system_clock> start, end;
        start = chrono::system_clock::now();
        m_sort(data, to_sort, 0, data.size());
        end = chrono::system_clock::now();

        // Calculate the time (in seconds) to do merge.
        chrono::duration<double> interval = end-start;

        merge_average += interval;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // For stl sort.
        to_sort = data;


        start = chrono::system_clock::now();
        sort(to_sort.begin(), to_sort.end());
        end = chrono::system_clock::now();

        // Calculate the time (in seconds) to do stl.
        interval = end-start;

        stl_average += interval;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        // For insertion sort.
        to_sort = data;

        start = chrono::system_clock::now();
        i_sort(to_sort);
        end = chrono::system_clock::now();
        // Calculate the time (in seconds) to do insertion.
        interval = end-start;

        insertion_average += interval;


      }
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      // Build the vectors for each sorting type..
      double s = stl_average.count()/2.0;
      double m = merge_average.count()/2.0;
      double is = insertion_average.count()/2.0;
      //double q = quick_average.count()/3;
      stl_times.push_back(s*1000.0);
      merge_times.push_back(m*1000.0);
      insertion_times.push_back(is*1000.0);
      //quick_times.push_back(q);
    }
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Make the Files
    ofstream fout;


    // STL file
    fout.open("./benchmarking/stl_cpp.txt");
    for(size_t i = 0; i != stl_times.size(); i++){
      fout << stl_times[i] << endl;;
    }
    fout.close();


    // merge file
    fout.open("./benchmarking/merge_cpp.txt");
    for(size_t i = 0; i != merge_times.size(); i++){
      fout << merge_times[i] << endl;
    }
    fout.close();


    // Insertion file
    fout.open("./benchmarking/insertion_cpp.txt");
    for(size_t i = 0; i != insertion_times.size(); i++){
      fout << insertion_times[i] << endl;
    }
    fout.close();

    // Soon-to-be quicksort.
    /*
    fout.open("./benchmarking/insertion_times.txt");
    for(size_t i = 0; i != stl_times.size(); i++){
      fout << insertion_times[i] << " ";
    }
    fout.close();
    */

    return 0;
}
