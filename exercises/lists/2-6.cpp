// Exercise 2.6 from CtCI p.95
// Check to see if linked list is palindrome
// Timothy Devon Morris
// Mon Jun  1 13:36:32 UTC 2020
#include <cassert>
#include <cstdio>
#include <list>
#include <stack>

/**
 * BCR is O(N)
 * You have to look at all the elements at least once
 * Best spatial complexity is O(N)
 * You can do this without knowing the size of the list
 * If you know the size of the list you only have to check half the list
 */

/**
 * @brief check and see if the list is a palindrome
 * @details
 * -# reverse list and check comparison
 * -# heavily leverages stl, but what I would do in real life
 * @param[in] input list
 */
template <typename DataType>
bool isPalindromeStl(std::list<DataType> input)
{
  std::list<DataType> input_reverse = input;
  input_reverse.reverse();
  return input == input_reverse;
}

/**
 * @brief check and see if the list is a palindrome
 * @details
 * -# compare forward and reverse iterators
 * -# only works for doubly linked lists
 * @param[in] input list
 */
template <typename DataType>
bool isPalindromeIterator(std::list<DataType> input)
{
  auto it = input.begin();
  auto r_it = input.rbegin();
  while (it != input.end())
  {
    if (*it != *r_it)
    {
      return false;
    }
    ++it;
    ++r_it;
  }
  return true;
}

/**
 * @brief check and see if the list is a palindrome
 * -# works with singly linked lists
 * -# comes at O(N) spatial complexity cost
 * @param[in] input list
 */
template <typename DataType>
bool isPalindromeStack(std::list<DataType> input)
{
  std::stack<DataType> stacked_input{};
  auto it = input.begin();
  // construct stack
  while (it != input.end())
  {
    stacked_input.emplace(*it);
    ++it;
  }

  // make reversed list
  std::list<DataType> input_reverse{};
  while (!stacked_input.empty())
  {
    input_reverse.emplace_back(stacked_input.top());
    stacked_input.pop();
  }
  return input == input_reverse;
}

int main(int argc, char* argv[])
{
  std::list<int> list1 {1,2,3,4,5};
  std::list<int> list2 {1,2,3,2,1};

  assert(!isPalindromeStl(list1));
  assert(!isPalindromeStack(list1));
  assert(!isPalindromeIterator(list1));

  assert(isPalindromeStl(list2));
  assert(isPalindromeStack(list2));
  assert(isPalindromeIterator(list2));

  printf("Test Cases Passed\n");
  return 0;
}
