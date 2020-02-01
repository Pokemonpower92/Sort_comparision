/*
    C++ protocol for testing the time to sort multiple input sizes for
    generic sorting algorithms.

    Sorting times for three differing arrays of random numbers are averaged
    for each input size.

    This averaged sorting time is stored in a file (for each algorithm);

    ##TODO-
      - Implement a quicksort in sorting.hpp
      - Add functionality for user-defined input.
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

    printf("Generating files.\n");
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    vector<double> stl_times;
    vector<double> merge_times;
    vector<double> insertion_times;
    vector<double> selection_times;

    ifstream fin;;

    fin.open("./io/rand_input.txt");

    if(fin.fail()){
      perror("./io/rand_input.txt");
    }

    for(int i = 1; i != 701; i++){

      // Average for each sort type.
      chrono::duration<double> stl_average;
      chrono::duration<double> merge_average;
      chrono::duration<double> insertion_average;
      chrono::duration<double> selection_average;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      // For each input size we have two lines to read then sort.
      // Finally, we average them.
      for(int j = 1; j != 3; j++){
        int num;
        vector<int> data;
        vector<int> to_sort;

        // Read in the data.
        for(int z = 0; z != i*10; z++){
            fin >> num;
            data.push_back(num);
        }


        to_sort = data;
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Done reading the input file. Time to run each
        // sorting implementation on the data.

        // For merge.
        chrono::time_point<chrono::system_clock> start, end;
        start = chrono::high_resolution_clock::now();
        m_sort(data, to_sort, 0, data.size());
        end = chrono::high_resolution_clock::now();

        // Calculate the time (in seconds) to do merge.
        chrono::duration<double> interval = end-start;

        merge_average += interval;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // For stl sort.
        to_sort = data;


        start = chrono::high_resolution_clock::now();
        sort(to_sort.begin(), to_sort.end());
        end = chrono::high_resolution_clock::now();

        // Calculate the time (in seconds) to do stl.
        interval = end-start;

        stl_average += interval;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        // For insertion sort.
        to_sort = data;

        start = chrono::high_resolution_clock::now();
        i_sort(to_sort);
        end = chrono::high_resolution_clock::now();
        // Calculate the time (in seconds) to do insertion.
        interval = end-start;

        insertion_average += interval;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        // For selection sort.
        to_sort = data;

        start = chrono::high_resolution_clock::now();
        s_sort(to_sort);
        end = chrono::high_resolution_clock::now();
        // Calculate the time (in seconds) to do insertion.
        interval = end-start;

        selection_average += interval;


      }
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      // Build the vectors for each sorting type..
      double s = (stl_average.count())/2.0;
      double m = (merge_average.count())/2.0;
      double is = (insertion_average.count())/2.0;
      double sl = (selection_average.count())/2.0;

      stl_times.push_back(s);
      merge_times.push_back(m);
      insertion_times.push_back(is);
      selection_times.push_back(sl);
    }
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    fin.close();

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

    // Selction file
    fout.open("./benchmarking/selction_cpp.txt");
    for(size_t i = 0; i != stl_times.size(); i++){
      fout << selection_times[i] << endl;
    }
    fout.close();

    return 0;
}
