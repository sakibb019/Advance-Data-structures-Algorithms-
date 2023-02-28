#ifndef _SORT_H_
#define _SORT_H_

#include <cmath>
#include <stdexcept>

namespace my_algorithm{
	
////////////////////////////////////////////////////////////////////////////////
/// @brief Swap values of two elements
/// @tparam T Value type
/// @param a First value
/// @param b Second value
template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Bubble Sort - Example
template<class RandomAccessIterator, class Compare>
  void bubble_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
    for(RandomAccessIterator i = first; i != last; ++i)
      for(RandomAccessIterator j = first; j+1 != last; ++j)
        if(comp(*(j+1), *j))
          swap(*(j+1), *j);
  }
	
////////////////////////////////////////////////////////////////////
/// @brief Your implementation of insertion or selection sort
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
///	Insertion Sort 
template<typename RandomIterator, typename Comparator>
void slow_sort(RandomIterator first, RandomIterator last, Comparator comp){
  for(RandomIterator i = first; i != last; ++i)
    for(RandomIterator j = i; j != first; --j)
      if(comp(*j, *(j-1)))
        swap(*j, *(j-1));

	/// @TODO
}
/// Selection Sort
template<typename RandomIterator, typename Comparator>
void slow_sort(RandomIterator first, RandomIterator last, Comparator comp){
  for(RandomIterator i = first; i != last; ++i){
    RandomIterator min = i;
    for(RandomIterator j = i+1; j != last; ++j)
      if(comp(*j, *min))
        min = j;
    swap(*i, *min);
  }
}
////////////////////////////////////////////////////////////////////
/// @brief Your implementation of quick sort
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.	
template<typename RandomIterator, typename Comparator>
void merge_sort(RandomIterator first, RandomIterator last, Comparator comp){
	/// @TODO
	/// Hint: To allocate external memory to store merging of result use
	/// std::vector<typename RandomAccessIterator::value_type> 
	/// Remember to copy back the merged result
  
  /// merge sort function
  if(std::distance(first, last) <= 1) return;
  RandomIterator mid = first + std::distance(first, last)/2;
  merge_sort(first, mid, comp);
  merge_sort(mid, last, comp);
  std::vector<typename RandomAccessIterator::value_type> tmp;
  RandomIterator i = first, j = mid;
  while(i != mid && j != last){
    if(comp(*i, *j))
      tmp.push_back(*i++);
    else
      tmp.push_back(*j++);
  }
  while(i != mid)
    tmp.push_back(*i++);
  while(j != last)
    tmp.push_back(*j++);
  std::copy(tmp.begin(), tmp.end(), first);
}

}

#endif