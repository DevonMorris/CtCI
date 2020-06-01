// Exercise 2.4 from CtCI p.94
// Partition a linked list
// Timothy Devon Morris
// Mon Jun  1 13:36:32 UTC 2020
#include <cassert>
#include <cstdio>
#include <functional>
#include <list>

/**
 * BCR is O(N)
 * Best spatial complexity would be O(1)
 */

/**
 * @brief partition list
 * @details
 * -# Loop over list and determine if value is less or greater than partition value
 * -# push elements less than value on front leave elements greater than value in place
 * -# O(N) runtime
 * -# O(1) spatial
 * @param[in] input list
 * @param[in] part partition value
 * @param[in] comp comparator
 */
template <typename DataType, typename Comp = std::less<DataType>>
void partitionList(std::list<DataType>& input, const DataType& part, Comp c = Comp())
{
  auto it = input.begin();
  while (it != input.end())
  {
    if (c(*it, part))
    {
      input.push_front(*it);
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
  std::list<int>list_in {1,4,2,5,8,3,5,4};
  std::list<int>list_out {4,3,2,4,1,5,8,5};

  assert(list_in != list_out);
  partitionList(list_in, 5);
  assert(list_in == list_out);

  printf("Test Cases Passed\n");
  return 0;
}
