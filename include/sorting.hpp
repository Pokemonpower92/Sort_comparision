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


template <class T>
void q_sort(vector<T> &vec);
template <class T>
void qsort_helper(vector<T> &vec, int start, int stop, int num);
template <class T>
void partition(vector<T> &vec, size_t pivot, size_t &left, size_t &right);



// Merges two subarrays of vec back into place in vec.
template <class T>
void merge(vector<T> &vec, size_t start, size_t mid, size_t size){
  T stuff[vec.size()];

  // Flags for where we are on the right and left sides of vec.
  size_t rhf = start;
  size_t lhf = mid;
  // This keeps track of where we are in the temp vector.
  int count = start;
  // We loop through placing the smaller of the right-hand-side or
  // left-hand-side of vec in the next slot of the temp vector.
  while(rhf < mid && lhf < start+size){
    if(vec[rhf] < vec[lhf]){
      stuff[count] = vec[rhf];
      rhf++;
      count++;
    }
    else{
      stuff[count] = vec[lhf];
      lhf++;
      count++;
    }
  }
  // Either the rhs or lhs is exhausted here.
  // We simply loop through the remaining elements
  // and place them in the temp vector.
  while(rhf < mid){
    stuff[count] = vec[rhf];
    rhf++;
    count++;
  }

  while(lhf < start+size){
    stuff[count] = vec[lhf];
    lhf++;
    count++;
  }

  // After all that we need to place the merged
  // elements in their place back in vec.
  for(size_t i = start; i != start+size; i++){
    vec[i] = stuff[i];
  }

  return;
}

template <class T>
void m_sort(vector<T> &vec, size_t start, size_t size){
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

      m_sort(vec, start, mid-start);
      m_sort(vec, mid, size - (mid-start));

      merge(vec, start, mid, size);

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



template <class T>
void q_sort(vector<T> &vec){
  qsort_helper(vec, 0, vec.size()-1, 0);
  return;
}

// Done
template <class T>
void qsort_helper(vector<T> &vec, int start, int stop, int num){
  //if(num == 20) return;

  // If one element return.
  if(stop-start <= 0){
    return;
  }
  // If two elements swap maybe.
  else if(stop-start == 1){
    if(vec[start] > vec[stop]){
      T temp = vec[start];
      vec[start] = vec[stop];
      vec[stop] = temp;
    }
    return;
  }
  // If neither is true we need to select our pivot and
  // then partition.

  // Find the median of the first, middle, and last elements.
  size_t middle = start + (stop-start)/2;
  size_t pivot = middle;
  //cout << "Middle: " << vec[middle] << endl;

  // Two ways for the start to be the pivot.
  if(vec[start] <= vec[stop] && vec[start] >= vec[middle]) pivot = start;
  if(vec[start] >= vec[stop] && vec[start] <= vec[middle]) pivot = start;

  // Same for the end.
  if(vec[stop] <= vec[start] && vec[stop] >= vec[middle]) pivot = stop;
  if(vec[stop] >= vec[start] && vec[stop] <= vec[middle]) pivot = stop;

  //cout << "Before pivot swap: ";
  //for(size_t i = start; i <= stop; i++) cout << vec[i] << " ";
  //cout << endl;

  // If the pivot isn't the first element swap it with the first element.
  if(pivot != start){
    T temp = vec[start];
    vec[start] = vec[pivot];
    vec[pivot] = temp;
  }

  size_t left = start+1;
  size_t right = stop;

  //cout << "After pivot swap: ";
  //for(size_t i = start; i <= stop; i++) cout << vec[i] << " ";
  //cout << endl;

  partition(vec, start, left, right);

  //cout << "After partition: ";
  //for(size_t i = start; i <= stop; i++) cout << vec[i] << " ";
  //cout << endl;
  //cout << "Left: " << left << " Right: " << right << endl;
  //cout << endl;

  qsort_helper(vec, start, left, num +1);
  qsort_helper(vec, right, stop, num +1);

  return;
}

// Work in progress.
template <class T>
void partition(vector<T> &vec, size_t pivot, size_t &left, size_t &right){

  while(left < right){
    // Find an element that is greater than the pivot.
    while(vec[left] < vec[pivot]){
      left++;

    }
    // Then find one less than the pivot.
    while(vec[right] > vec[pivot]){
      right--;
    }

    if(left < right){
      // We're not done yet.
      // Swap, change left and right, continue.
      T temp = vec[right];
      vec[right] = vec[left];
      vec[left] = temp;
      left++;
      right--;
    }

  }
  // We're done. Left is either greater than or equal to right.
  if(left > right){
    T temp = vec[right];
    vec[right] = vec[pivot];
    vec[pivot] = temp;

    size_t swap = right-1;
    right = left;
    left = swap;
    return;
  }
  else{
    if(vec[left] < vec[pivot]){
      // simply swap with the pivot.
      T temp = vec[right];
      vec[right] = vec[pivot];
      vec[pivot] = temp;

      size_t swap = right-1;
      right = left;
      left = swap;

      right++;

      return;
    }
    // If left == right but is greater than the pivot.
    else{

      // Make this prettier.
      right--;

      T temp = vec[right];
      vec[right] = vec[pivot];
      vec[pivot] = temp;

      right--;

      size_t swap = right;
      right = left;
      left = swap;

      return;
    }
  }
}
