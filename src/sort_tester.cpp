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
    for(int i = 3; i != 4; i++){
      ofstream fout;
      char outfile[100];

      // Average for each sort type.
      chrono::duration<double> stl_average;
      chrono::duration<double> merge_average;
      chrono::duration<double> quick_average;
      chrono::duration<double> insertion_average;
      chrono::duration<double> selction_average;

      sprintf(outfile, "./benchmarking/time%d.txt", i);

      fout.open(outfile);
      if(fout.fail()){
        perror(outfile);
      }


      // For each file for that size
      for(int j = 1; j != 6; j++){
        ifstream fin;
        char infile[100];
        int num;
        vector<int> data;
        // this is the vector we sort.
        vector<int> to_sort;
        // temp vector for merge_sort
        vector<int> ret;
        //sprintf(infile, "./io/rand%d%d.txt", i, j);

        fin.open("./io/rand31.txt");
        if(fin.fail()){
          perror(infile);
        }

        // Read in the data.
        while(fin >>  num){
            data.push_back(num);
        }

        to_sort = data;
        // Sort the file with merge sort.
        chrono::time_point<chrono::system_clock> start, end;
        start = chrono::system_clock::now();
        m_sort(data, ret, 0, data.size());
        end = chrono::system_clock::now();

        chrono::duration<double> interval = end-start;

        cout << interval.count() << endl;
        merge_average += interval;
        fin.close();
      }
      cout << "Merge Average: " << merge_average.count()/5 << endl;
      // Divide each average by five and write them to outfile.
      fout.close();
    }

    return 0;
}
