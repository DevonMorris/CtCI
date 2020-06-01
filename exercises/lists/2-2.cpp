// Exercise 2.2 from CtCI p.94
// Find kth to last element in singly linked list
// Timothy Devon Morris
// Mon Jun  1 13:36:32 UTC 2020

#include <cassert>
#include <cstdio>
#include <list>

/**
 * BCR is O(N)
 * This is because you have to loop through the list once to know
 * The size of the list before you can return the kth to last element
 */

/**
 * @brief return Kth to last element of list
 * @details
 * -# Loop over list to find size
 * -# Note: we could use size function but that's O(N) as well
 * -# Note Note: Yes, in C++11 the standard says O(1) but _actually_
 * -# libstdc++ is O(N), because should vs shall
 * -# Do some math to find index of Kth to last element and
 * -# Loop through again to find element
 * -# return nullptr if k > size of list or if k < 0
 * -# O(N)
 */
//template <typename DataType>
//DataType* kToLast(std::list<DataType>& input, size_t k)
//{
  //// Find size of list
  //size_t size = 0;
  //for (auto it = input.begin(); it != input.end(); ++it)
  //{
    //++size;
  //}

  //if (k > (size - 1))
  //{
    //return nullptr;
  //}

  //const size_t idx = size - k - 1;
  //auto it = input.begin();
  //for (size_t i = 0; i < idx; ++i)
  //{
    //++it;
  //}
  //return &(*it);
//}

/**
 * @brief return Kth to last element of list
 * @details
 * -# Place an iterator at position k and place another iterator at 0
 * -# Increment iterators until k iterator reaches last element
 * -# Loop through again to find element
 * -# return nullptr if k > size of list or if k < 0
 * -# Note: with this we only have to loop through the list once and
 * -# we don't need to calculate the size of the list first
 * -# O(N)
 */
template <typename DataType>
DataType* kToLast(std::list<DataType>& input, size_t k)
{
  if (input.begin() == input.end())
  {
    return nullptr;
  }

  // Put an iterator at position k
  auto it_k = input.begin();
  for (size_t i = 0; i < k; ++i)
  {
    ++it_k;
    // Check to see if past end of list
    if (it_k == input.end())
    {
      return nullptr;
    }
  }

  auto it = input.begin();
  while (++it_k != input.end())
  {
    ++it;
  }
  return &(*it);
}

int main(int argc, char* argv[])
{
  std::list<int> list_in {1,2,2,3,3,3,4,4,4,4,1,1,1,5};

  assert(kToLast(list_in, 30) == nullptr);
  assert(*kToLast(list_in, 0) == 5);
  assert(*kToLast(list_in, 1) == 1);
  assert(*kToLast(list_in, 4) == 4);

  printf("Test Cases Passed\n");
  return 0;
}

