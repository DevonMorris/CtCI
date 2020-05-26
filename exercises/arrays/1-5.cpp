// Exercise 1.5 from CtCI p.91
// Check to see if string is palindrome
// Timothy Devon Morris
// Mon May 25 22:30:39 UTC 2020
#include <cmath>
#include <cassert>
#include <string>

/**
 * BCR is O(min(n,m)) since you have to iterate over both strings
 * Best spatial complexity is O(1)
 */

/**
 * @brief check to see strings are one edit different
 * @details
 * -# Addition or subtraction is really the same operation if you switch arguments
 * -# Assume str1.length() < str2.length()
 * -# if the assumption doesn't hold swap strings
 * -# So only two valid options, addition and change letter
 * -# O(min(m,n)) temporal complexity
 * -# O(1) spatial complexity
 */
bool areOneEditDifferent(std::string str1, std::string str2)
{
  // Early exit condition for equality
  if (str1 == str2)
  {
    return true;
  }

  if(str1.length() > str2.length())
  {
    std::swap(str1, str2);
  }

  // Early exit condition for length
  if (str1.length() < str2.length() - 1)
  {
    return false;
  }

  // different sizes find addition
  if (str2.length() > str1.length())
  {
    int i = 0;
    int j = 0;
    while (i < str1.size())
    {
      if (str1[i] != str2[j])
      {
        ++j;
      }
      else
      {
        ++i;
        ++j;
      }
      if (j - i > 1)
      {
        return false;
      }
    }
  }
  else
  {
    int num_diff = 0;
    for (int i = 0; i < str1.size(); ++i)
    {
      if (str1[i] != str2[i])
      {
        ++num_diff;
      }
      if (num_diff > 1)
      {
        return false;
      }
    }
  }
  return true;
}

int main(int argc, char* argv[])
{
  std::string str1 = "rake";
  std::string str2 = "bake";
  std::string str3 = "brake";
  std::string str4 = "brakes";

  assert(areOneEditDifferent(str1,str2));
  assert(areOneEditDifferent(str2,str1));
  assert(areOneEditDifferent(str2,str3));
  assert(areOneEditDifferent(str3,str2));
  assert(areOneEditDifferent(str3,str4));
  assert(areOneEditDifferent(str4,str3));
  assert(!areOneEditDifferent(str1,str4));
  assert(!areOneEditDifferent(str4,str1));
  assert(areOneEditDifferent(str1,str3));
  assert(areOneEditDifferent(str3,str1));

  printf("Test Cases Passed\n");
  return 0;
}
