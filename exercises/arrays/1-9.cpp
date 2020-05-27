// Exercise 1.9 from CtCI p.91
// Determine if string is rotated string with isSubstring
// Timothy Devon Morris
// Wed May 27 02:38:23 UTC 2020
#include <cassert>
#include <string>

/**
 * BCR is O(N)
 */

/**
 * @brief determine if str1 is substring of str2
 */
bool isSubstring(std::string str1, std::string str2)
{
  auto p = str2.find(str1);
  return p != std::string::npos;
}

/**
 * @brief determine if str2 is a rotated version of str1
 * @details
 *  -# append str2 to itself and call isSubstring on that
 */
bool isRotatedString(std::string str1, std::string str2)
{
  return isSubstring(str1, str2 + str2);
}

int main(int argc, char* argv[])
{
  std::string str1 = "hello";
  std::string str2 = "bob";
  std::string str3 = "llohe";

  assert(!isRotatedString(str1, str2));
  assert(isRotatedString(str1, str3));

  printf("Test Cases Passed\n");
  return 0;
}
