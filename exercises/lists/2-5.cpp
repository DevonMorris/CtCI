// Exercise 2.5 from CtCI p.95
// Add numbers (2 linked lists)
// Timothy Devon Morris
// Mon Jun  1 13:36:32 UTC 2020
#include <cassert>
#include <cstdio>
#include <list>

/**
 * BCR is O(min(N,M))
 * Best spatial complexity is O(max(N,M))
 */

/**
 * @brief add two integers stored as linked lists
 * @details
 * -# loop over lists together and add numbers, being careful to carry over
 * @param[in] list1 first list to add
 * @param[in] list2 second list to add
 * return list of output
 */
std::list<unsigned int> addIntegers(const std::list<unsigned int>& list1, const std::list<unsigned int>& list2)
{
  std::list<unsigned int> output{};
  auto it1 = list1.begin();
  auto it2 = list2.begin();
  bool carry = false;
  while (it1 != list1.end()
         && it2 != list2.end())
  {
    unsigned int sum = *it1 + *it2;
    if (carry)
    {
      carry = false;
      ++sum;
    }

    if (sum > 9)
    {
      sum %= 10;
      carry = true;
    }

    output.emplace_back(sum);

    ++it1;
    ++it2;
  }

  while (it1 != list1.end())
  {
    unsigned int sum = *it1;
    if (carry)
    {
      carry = false;
      ++sum;
    }

    if (sum > 9)
    {
      sum %= 10;
      carry = true;
    }

    ++it1;
    output.emplace_back(sum);
  }

  while (it2 != list2.end())
  {
    unsigned int sum = *it2;
    if (carry)
    {
      carry = false;
      ++sum;
    }

    if (sum > 9)
    {
      sum %= 10;
      carry = true;
    }

    ++it2;
    output.emplace_back(sum);
  }

  return output;
}

int main(int argc, char* argv[])
{
  std::list<unsigned int>list1 {1, 9, 9, 1, 1};
  std::list<unsigned int>list2 {9};
  std::list<unsigned int>list3 {0, 0, 0, 2, 1};

  auto output = addIntegers(list1, list2);
  assert(list3 == output);

  printf("Test Cases Passed\n");
  return 0;
}
