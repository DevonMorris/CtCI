// Exercise 1.3 from CtCI p.91
// Check to see if string is palindrome
// Timothy Devon Morris
// Mon May 25 15:23:40 UTC 2020
#include <algorithm>
#include <cassert>
#include <cctype>
#include <locale>
#include <functional>
#include <string>
#include <unordered_map>

/**
 * BCR is O(n) temporal since letters have to be checked at least once
 */

/**
 * @brief check to see if string has permuation that is palindrome
 * @details
 * -# Convert to lowercase
 * -# Remove whitespace
 * -# Iterate through new string and store frequencies in map
 * -# Check size and if odd allocate one odd numbered frequency
 * -# Assure all frequencies are even (except one if odd length)
 * -# return true if conditions of palindrome are met, false otherwise
 * -# O(n) temporal complexity
 * -# O(n) spatial complexity
 */
bool hasPalindromePermutationMap(std::string& input)
{
  std::transform(input.begin(), input.end(), input.begin(),
      [](unsigned char c){return std::tolower(c);});
  input.erase(std::remove_if(input.begin(), input.end(),
      [](unsigned char c){return std::isspace(c);}), input.end());
  // Note: this must be an unordered_map which has amortized insert O(1)
  std::unordered_map<char, int> char_freq;

  for (auto c : input)
  {
    auto p = char_freq.emplace(c, 1);
    if (!p.second)
    {
      ++(p.first->second);
    }
  }

  int num_odd = 0;
  if (input.length() % 2 == 1)
  {
    num_odd = 1;
  }

  for (auto it = char_freq.begin(); it != char_freq.end(); ++it)
  {
    if (num_odd < 0)
    {
      return false;
    }

    if((it->second % 2) == 1)
    {
      --num_odd;
    }
  }
  return true;
}

int main(int argc, char* argv[])
{
  std::string str1 = "abcdefgh";
  std::string str2 = "abcdedcba";
  std::string str3 = "dcdcaaebb";
  std::string str4 = "aacaacabba";

  assert(!hasPalindromePermutationMap(str1));
  assert(hasPalindromePermutationMap(str2));
  assert(hasPalindromePermutationMap(str3));
  assert(hasPalindromePermutationMap(str4));

  printf("Test Cases Passed\n");
  return 0;
}
