// Exercise 1.8 from CtCI p.91
// Make zeros in matrix
// Timothy Devon Morris
// Wed May 27 01:18:56 UTC 2020
#include <cassert>
#include <cstdio>

/**
 * BCR is O(MN)
 * Best spatial complexity is O(1) if done in place
 */

/**
 * @brief if a row contains a zero set all entries in that row to 0
 *        similarly for columns
 * @details
 *  -# O(MN) temporal complexity
 *  -# O(1) spatial complexity
 */
template <typename DataType, typename SizeType>
void zeroRowColumn(DataType mat, SizeType n_rows, SizeType n_cols)
{
  bool zero_first_row = false;
  bool zero_first_column = false;

  // Iterate through and mark which rows/columns need to be zeroed
  for (size_t i = 0; i < n_rows; ++i)
  {
    for (size_t j = 0; j < n_cols; ++j)
    {
      if (mat[i][j] == 0)
      {
        if (i == 0 && j == 0)
        {
          zero_first_row = true;
          zero_first_column = true;
        }
        else if (i == 0)
        {
          zero_first_row = true;
        }
        else if (j == 0)
        {
          zero_first_column = true;
        }
        else
        {
          mat[i][0] = 0;
          mat[0][j] = 0;
        }
      }
    }
  }

  // Iterate through first row and set columns to zero
  for (size_t j = 1; j < n_cols; ++j)
  {
    if (mat[0][j] == 0)
    {
      for (size_t i = 1; i < n_rows; ++i)
      {
        mat[i][j] = 0;
      }
    }
  }

  // Iterate through first column and set rows to zero
  for (size_t i = 1; i < n_rows; ++i)
  {
    if (mat[i][0] == 0)
    {
      for (size_t j = 1; j < n_cols; ++j)
      {
        mat[i][j] = 0;
      }
    }
  }

  // First row
  if (zero_first_row)
  {
    for (size_t j = 0; j < n_cols; ++j)
    {
      mat[0][j] = 0;
    }
  }

  // First column
  if (zero_first_column)
  {
    for (size_t i = 0; i < n_rows; ++i)
    {
      mat[i][0] = 0;
    }
  }
  return;
}

int main(int argc, char* argv[])
{
  int arr[5][3] = {{1,2,3},
                   {4,0,6},
                   {7,8,9},
                   {10,11,0},
                   {12,13,14}};

  int arr_zeroed[5][3] = {{1,0,0},
                          {0,0,0},
                          {7,0,0},
                          {0,0,0},
                          {12,0,0}};

  zeroRowColumn(arr, 5, 3);
  for (int i = 0; i < 5; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      assert(arr[i][j] == arr_zeroed[i][j]);
    }
  }

  printf("Test Cases Passed\n");
  return 0;
}
