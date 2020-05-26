// Exercise 1.6 from CtCI p.91
// Compress a string
// Timothy Devon Morris
// Tue May 26 23:19:44 UTC 2020
#include <cassert>
#include <sstream>
#include <string>

/**
 * BCR is O(n) since you will have to iterate through the string once
 * Best spatial complexity is O(1) if we edit in place
 */

/**
 * @brief Compress a String by replacing repeated letters
 * -# Iterate through array and count letters as they occur
 * -# Put letters and counts into string stream
 * -# Compare initial string length to final string length and
 * -# return shorter string
 * -# O(n) temporal complexity
 * -# O(n) spatial complexity
 */
std::string compressString(std::string input)
{
  std::stringstream ss;
  int i = 0;
  while (i < input.length())
  {
    const auto c = input[i];
    unsigned int num_c = 0;
    while(i < input.length() && input[i] == c)
    {
      ++i;
      ++num_c;
    }
    ss << c << num_c;
  }
  auto compressed_str = ss.str();
  return compressed_str.length() < input.length() ? compressed_str : input;
}

int main(int argc, char* argv[])
{
  std::string str1 = "aabbbcccc";
  std::string str2 = "abcdefgh";

  std::string ans1 = "a2b3c4";

  assert(compressString(str1) == ans1);
  assert(compressString(str2) == str2);

  printf("Test Cases Passed\n");
  return 0;
}
