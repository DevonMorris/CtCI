// Exercise 1.2 from CtCI p.90
// Determine if two strings are permutations of one another
// Timothy Devon Morris
// Sun May 24 16:02:20 UTC 2020
#include <algorithm>
#include <cassert>
#include <functional>
#include <string>
#include <unordered_map>

/**
 * @brief compare two strings and see if they are permutations of one another
 * @details
 * -# sort each string
 * -# compare the strings
 * -# O(nlogn + mlogm) temporal complexity where n,m are string lengths
 * -# O(1) spatial complexity
 * @param[in] str1 - first string
 * @param[in] str2 - second string
 * @return true if strings are permuations, false otherwise
 */
bool isPermutationSort(std::string& str1, std::string& str2)
{
  if (str1.size() != str2.size())
  {
    return false;
  }

  std::sort(str1.begin(), str1.end());
  std::sort(str2.begin(), str2.end());
  return str1 == str2;
}

/**
 * @brief compare two strings and see if they are permutation sof one another
 * @details
 * -# iterate through each string and store frequency of char in map
 * -# compare maps
 * -# O(m + n) temporal complexity
 * -# O(m + n) spatial complexity
 */
bool isPermutationMap(const std::string& str1, const std::string& str2)
{
  if (str1.size() != str2.size())
  {
    return false;
  }

  std::unordered_map<char, size_t> str1_map;
  std::unordered_map<char, size_t> str2_map;

  for (const auto c : str1)
  {
    auto p = str1_map.emplace(c,1);
    if (!p.second)
    {
      ++(p.first->second);
    }
  }

  for (const auto c : str2)
  {
    auto p = str2_map.emplace(c,1);
    if (!p.second)
    {
      ++(p.first->second);
    }
  }

  return str1_map == str2_map;
}

int main(int argc, char* argv[])
{
  std::string str1 = "abcdefgh";
  std::string str2 = "hgfedcba";
  std::string str3 = "abdcdfff";

  assert(isPermutationMap(str1,str2));
  assert(isPermutationSort(str1,str2));

  assert(!isPermutationMap(str1,str3));
  assert(!isPermutationSort(str1,str3));

  assert(!isPermutationMap(str2,str3));
  assert(!isPermutationSort(str2,str3));

  printf("Test Cases Passed\n");
  return 0;
}
