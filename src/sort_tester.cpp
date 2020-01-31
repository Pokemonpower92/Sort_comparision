#include "sorting.hpp"
#include <iostream>
#include <cstdio>
#include <chrono>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
    // Average the time to sort five random input files of size
    // 10^3 10^4 10^5 10^6 10^7 for each sort

    // For each input size
    for(int i = 1; i != 8; i++){
      ofstream fout;
      char outfile[100];

      // Average for each sort type.
      chrono::duration<double> stl_average;
      chrono::duration<double> merge_average;
      // TODO Need to implement a quicksort.
      //chrono::duration<double> quick_average;
      chrono::duration<double> insertion_average;
      chrono::duration<double> selection_average;

      sprintf(outfile, "./benchmarking/time%d.txt", i);

      fout.open(outfile);
      if(fout.fail()){
        perror(outfile);
      }


      // For each file for that size
      for(int j = 1; j != 4; j++){
        ifstream fin;
        char infile[100];
        int num;
        vector<int> data;
        // this is the vector we sort.
        vector<int> to_sort;
        // temp vector for merge_sort
        vector<int> ret;
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

        // Done reading the input file. Time to run each
        // sorting implementation on the data.

        // For merge.
        chrono::time_point<chrono::system_clock> start, end;
        start = chrono::system_clock::now();
        m_sort(data, ret, 0, data.size());
        end = chrono::system_clock::now();

        // Calculate the time (in seconds) to do merge.
        chrono::duration<double> interval = end-start;

        merge_average += interval;

        // For stl sort.
        to_sort = data;


        start = chrono::system_clock::now();
        sort(to_sort.begin(), to_sort.end());
        end = chrono::system_clock::now();

        // Calculate the time (in seconds) to do stl.
        interval = end-start;

        stl_average += interval;

        // For insertion sort.
        to_sort = data;

        start = chrono::system_clock::now();
        i_sort(to_sort);
        end = chrono::system_clock::now();
        // Calculate the time (in seconds) to do insertion.
        interval = end-start;

        insertion_average += interval;

        // For selection sort.
        to_sort = data;

        start = chrono::system_clock::now();
        s_sort(to_sort);
        end = chrono::system_clock::now();

        // Calculate the time (in seconds) to do selection.
        interval = end-start;

        selection_average += interval;

      }

      // Build the outfile.
      fout << stl_average.count()/3 << endl;
      fout << merge_average.count()/3 << endl;
      fout << insertion_average.count()/3 << endl;
      fout << selection_average.count()/3 << endl;

      cout << "Run: " << i << endl;
      cout << "STL: " << stl_average.count()/3 << endl;
      cout << "Merge: " << merge_average.count()/3 << endl;
      cout << "Insertion: " << insertion_average.count()/3 << endl;
      cout << "Selection: " << selection_average.count()/3 << endl;
      cout << endl;

      fout.close();
    }

    return 0;
}
