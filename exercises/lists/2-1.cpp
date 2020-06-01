// Exercise 2.1 from CtCI p.91
// Remove duplicates from a list
// Timothy Devon Morris
// Mon Jun  1 12:49:41 UTC 2020
#include <cassert>
#include <cstdio>
#include <list>
#include <unordered_set>

/**
 * BCR is O(N)
 * Best spatial complexity is O(1) without using extra buffer
 */

/**
 * @brief Remove duplicates from a list
 * @details
 * -# Loop through list storing values in set
 * -# If value is already found in set, remove it from the list
 * -# O(N) temporal complexity
 * -# O(N) spatial complexity
 */
template <typename DataType>
void removeDuplicates(std::list<DataType>& input)
{
  std::unordered_set<DataType> unique_elements{};
  for (auto it = input.begin(); it != input.end();)
  {
    auto p = unique_elements.emplace(*it);
    if (!p.second)
    {
      it = input.erase(it);
    }
    else
    {
      ++it;
    }
  }
  return;
}

int main(int argc, char* argv[])
{
  std::list<int> list_in {1,2,2,3,3,3,4,4,4,4,1,1,1,5};
  std::list<int> list_out {1,2,3,4,5};

  assert(list_in != list_out);
  removeDuplicates(list_in);
  assert(list_in == list_out);

  printf("Test Cases Passed\n");
  return 0;
}
