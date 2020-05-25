// Exercise 1.3 from CtCI p.90
// Replace all spaces in string with %20
// Timothy Devon Morris
// Mon May 25 13:35:19 UTC 2020
#include <cassert>
#include <string>

/**
 * BCR is O(n) temporal and O(1) spatial
 * Since " " is fewer char tha "%20" copying values will cause O(n^2)
 */

/**
 * @brief replace all spaces in a string by %20
 * @details
 * -# Iterate through string and find number of spaces
 * -# Calculate final index of urlified string
 * -# iterate backwards through string.
 * -# If the character is a space insert %20 and decrement final idx
 * -# If not space, copy value to final idx and decrement
 * -# O(n) temporal complexity
 * -# O(1) spatial complexity
 */
void urlify(char *const input, size_t size)
{
  if (size < 1)
  {
    return;
  }

  size_t num_spaces = 0;
  for (size_t i = 0; i < size; ++i)
  {
    if (input[i] == ' ')
    {
      ++num_spaces;
    }
  }

  size_t final_idx = size + 2 * num_spaces;
  for (int i = size - 1; i >= 0; --i)
  {
    if (input[i] == ' ')
    {
      input[final_idx - 3] = '%';
      input[final_idx - 2] = '2';
      input[final_idx - 1] = '0';
      final_idx -= 3;
    }
    else
    {
      input[final_idx - 1] = input[i];
      --final_idx;
    }
  }
}

int main(int argc, char* argv[])
{
  char str1[50] = "my name is devon\0                ";
  char str2[50] = "my%20name%20is%20devon\0          ";

  urlify(str1, 18);

  assert(std::string(str1) == std::string(str2));

  printf("Test Cases Passed\n");
  return 0;
}
