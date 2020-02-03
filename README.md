# WORK IN PROGRESS -- Figures not representative of final data

# Sort_comparision
Compares various sorting algorithms between python and c++ implementations
over an input range of 1 to 7000 elements.

The time to sort two random arrays of each input size are averaged to increase fidelity.  

\- Python in production.  


# To compile:  
    ``` make``` Compiles the c++ sorting comparision.  
    ``` make files``` generates the time to sort files in benchmarking.
    ``` make graph``` graphs the current data set.  
    ``` make new_graph``` generates a new data set then graphs it.

# Dependencies:   
   Matplotlib for graphing.

# Graphs   

   Fig 1. C++ Sort comparision.
   ![](https://github.com/Pokemonpower92/Sort_comparision/blob/master/graphs/Figure_1.png)  

   Fig 2. Characteristic Better Performance of Insertion on smaller input sizes  
   ![](https://github.com/Pokemonpower92/Sort_comparision/blob/master/graphs/Figure_2.png)  
     
   Fig 3. nlogn Sorts
      ![](https://github.com/Pokemonpower92/Sort_comparision/blob/master/graphs/MvQvS.png)

# TODO
Implement quicksort for c++  
Implement data generation program for python sorting implementations.  
