#pragma once
#include <iostream>
#include <vector>

using namespace std;



template <class T>
void merge(vector<T> &vec, vector<T> &ret, size_t start, size_t mid, size_t size);
template <class T>
void m_sort(vector<T> &vec, vector<T> &ret, size_t start, size_t size);

template <class T>
void i_sort(vector<T> &vec);

template <class T>
void s_sort(vector<T> &vec);
template <class T>
size_t sort_helper(vector<T> &vec, size_t index);

// Future implementation.
//template <class T>
//void q_sort(vector<T> &vec);

// Merges two subarrays of vec back into place in vec.
template <class T>
void merge(vector<T> &vec, vector<T> &ret, size_t start, size_t mid, size_t size){
  ret.clear();
  ret.resize(vec.size());

  // Flags for where we are on the right and left sides of vec.
  size_t rhf = start;
  size_t lhf = mid;
  // This keeps track of where we are in the temp vector.
  int count = start;

  // We loop through placing the smaller of the right-hand-side or
  // left-hand-side of vec in the next slot of the temp vector.
  while(rhf < mid && lhf < start+size){
    if(vec[rhf] < vec[lhf]){
      ret[count] = vec[rhf];
      rhf++;
      count++;
    }
    else{
      ret[count] = vec[lhf];
      lhf++;
      count++;
    }
  }

  // Either the rhs or lhs is exhausted here.
  // We simply loop through the remaining elements
  // and place them in the temp vector.
  while(rhf < mid){
    ret[count] = vec[rhf];
    rhf++;
    count++;
  }

  while(lhf < start+size){
    ret[count] = vec[lhf];
    lhf++;
    count++;
  }

  // After all that we need to place the merged
  // elements in their place back in vec.
  for(size_t i = start; i != start+size; i++){
    vec[i] = ret[i];
  }

  return;
}

template <class T>
void m_sort(vector<T> &vec, vector<T> &ret, size_t start, size_t size){
    // If the subarray is only one element long, its already sorted.
    if(size == 1) return;
    // If it's two elements long, then we need to sort those two elements.
    // Potentially.
    else if (size == 2){
      // Already sorted just return.
      if(vec[start] < vec[start +1]) return;
      // Not sorted. Just swap them.
      else{
        T temp = vec[start];
        vec[start] = vec[start+1];
        vec[start+1] = temp;

        return;
      }
    }
    // For all other cases where len(subarray) > 2 we need to keep splitting
    // it in two. after we've done that, and sorted each subarry, we merge
    // them together up the recursion stack.
    else{
      size_t mid = start + size/2;

      m_sort(vec, ret, start, mid-start);
      m_sort(vec, ret, mid, size - (mid-start));

      merge(vec, ret, start, mid, size);

      return;
    }
}

// Generic Insertion sort implementation
template <class T>
void i_sort(vector<T> &vec){
  for(size_t i = 0; i < vec.size()-1; i++){
    if(vec[i+1] > vec[i]) continue;

    for(size_t j = 0; j <= i; j++){
      if(vec[i+1] < vec[j]){
        T temp = vec[i+1];
        for(size_t r = i+1; r > j; r--){
          vec[r] = vec[r-1];
        }
        vec[j] = temp;
      }
      else continue;
    }
  }
}

// The following two are selection sort and a helper.
template <class T>
void s_sort(vector<T> &vec){
  for(size_t i = 0; i < vec.size()-1; i++){
    size_t min = sort_helper(vec, i);
    if(vec[min] < vec[i]){
      T swap_val = vec[min];
      vec[min] = vec[i];
      vec[i] = swap_val;
    }
  }
}

template <class T>
size_t sort_helper(vector<T> &vec, size_t index){
  size_t min = index;

  for(size_t i = index+1; i < vec.size(); i++){
    if( vec[i] < vec[min] ) min = i;
  }

  return min;
}
