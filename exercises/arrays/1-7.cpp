// Exercise 1.7 from CtCI p.91
// rotate NxN matrix
// Timothy Devon Morris
// Tue May 26 23:48:51 UTC 2020
#include <algorithm>
#include <cassert>
#include <cstdio>

/**
 * BCR is O(N^2)
 * Best spatial complexity is O(1) if done in place
 */

template <typename DataType, typename SizeType>
void rotateMatrix(DataType mat, SizeType size)
{
  if (size < 2)
  {
    return;
  }

  // Transpose
  for (size_t i = 0; i < size; ++i)
  {
    for (size_t j = 0; j < i; ++j)
    {
      std::swap(mat[i][j], mat[j][i]);
    }
  }

  // Flip Horizontal
  for (size_t i = 0; i < size; ++i)
  {
    for (size_t j = 0; j < size / 2; ++j)
    {
      std::swap(mat[i][j], mat[i][size - j - 1]);
    }
  }
  return;
}

int main(int argc, char* argv[])
{
  int arr1[3][3] = {{1,2,3},
                    {4,5,6},
                    {7,8,9}};

  int arr1_rotated[3][3] = {{7,4,1},
                            {8,5,2},
                            {9,6,3}};

  rotateMatrix(arr1, 3);
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      assert(arr1[i][j] == arr1_rotated[i][j]);
    }
  }

  printf("Test Cases Passed\n");
  return 0;
}
