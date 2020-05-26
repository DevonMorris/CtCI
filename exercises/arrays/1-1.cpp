// Exercise 1.1 from CtCI p.90
// Detect if a string has repeating characters
// Timothy Devon Morris
// Sun May 24 16:02:20 UTC 2020
#include <algorithm>
#include <cassert>
#include <functional>
#include <string>
#include <unordered_set>

/**
 * @brief detect if string has repeating characters
 * @details
 *  -# store characters in set and
 *  -# O(n) temporal complexity
 *  -# O(n) spatial complexity
 *  -# Since we copy the array we can pass by const&
 * @param[in] - str string to detect repeating char
 * @return true if string has repeating char, false otherwise
 */
bool hasRepeatingCharSet(std::string const& input)
{
  if (input.length() <= 1)
  {
    return true;
  }

  std::unordered_set<char> char_set(input.cbegin(), input.cend());
  return input.length() != char_set.size();
}

/**
 * @brief detect if string has repeating characters
 * @details
 *  -# sort string and then iterate through to find repeated char
 *  -# O(nlogn) temporal complexity
 *  -# O(1) spatial complexity
 *  -# cannot pass by const ref because we have to sort the array in place
 */
bool hasRepeatingCharSort(std::string& input)
{
  if (input.length() <= 1)
  {
    return true;
  }

  std::sort(input.begin(), input.end());
  char prev_char = input.front();
  for (int i = 1; i < input.length(); ++i)
  {
    if (input[i] == prev_char)
    {
      return true;
    }
    prev_char = input[i];
  }
  return false;
}

int main(int argc, char* argv[])
{
  std::string str1("abcdefgh");
  std::string str2("aaabbaaccc");

  assert(!hasRepeatingCharSet(str1));
  assert(hasRepeatingCharSet(str2));

  assert(!hasRepeatingCharSort(str1));
  assert(hasRepeatingCharSort(str2));

  printf("Test Cases Passed\n");
  return 0;
}
