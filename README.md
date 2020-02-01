# Sort_comparision
Compares various sorting algorithms between python and c++ implementations
over an input range of 10 to 5000 elements.

Three random sets of each interval are averaged to increase stochasticity.  

C++ implementation done \- Python in production.  


To compile:  
    ``` make``` Compiles the c++ sorting comparision.  
    ``` make files``` generates the time to sort files in benchmarking (provided /benchmarking exists)  
    ``` make graph``` graphs the current data set.  
    ``` make new_graph``` generates a new data set then graphs it.

   Fig 1. C++ Sort comparision.
   ![](https://github.com/Pokemonpower92/Sort_comparision/blob/master/graphs/Figure_1.png)  


   Fig 2. Characteristic Better Performance of Insertion on smaller input sizes
   ![](https://github.com/Pokemonpower92/Sort_comparision/blob/master/graphs/Figure_2.png)

## TODO

Implement quicksort for c++
Implement data generation program for python sorting implementations.
