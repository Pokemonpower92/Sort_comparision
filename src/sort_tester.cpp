/*
    C++ protocol for testing the time to sort multiple input sizes for
    generic sorting algorithms.

    Sorting times for three differing arrays of random numbers are averaged
    for each input size.

    This averaged sorting time is stored in a file (for each input size) like so:

    [stl_average]
    [merge_average]
    [insertion_average]

    With each average on its on line and given in seconds.


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
    // For each input size we create a file that holds each averaged runtime
    // on a new line.
    for(int i = 1; i != 8; i++){
      ofstream fout;
      char outfile[100];

      // Average for each sort type.
      chrono::duration<double> stl_average;
      chrono::duration<double> merge_average;
      chrono::duration<double> insertion_average;
      //chrono::duration<double> quick_average;
      sprintf(outfile, "./benchmarking/time%d.txt", i);

      fout.open(outfile);
      if(fout.fail()){
        perror(outfile);
      }

      printf("Generating file: %d\n", i);
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      // For each file for that size we need to add the runtime for each random
      // input to the running total of runtime for that sort.
      for(int j = 1; j != 4; j++){
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

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /*
        // Placeholder for quicksort.
        to_sort = data;

        start = chrono::system_clock::now();
        quick_sort(to_sort);
        end = chrono::system_clock::now();

        // Calculate the time (in seconds) to do selection.
        interval = end-start;

        quick_average += interval;
        */
      }
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      // Build the outfile.
      fout << stl_average.count()/3 << endl;
      fout << merge_average.count()/3 << endl;
      fout << insertion_average.count()/3 << endl;
      //fout << quick_average.count()/3 << endl;


      fout.close();
    }

    return 0;
}
