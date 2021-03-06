/*
 * Chapter 16
 * Paragraph 4
 */

#include <set>
#include <iostream>
#include <cassert>

using namespace std;

void processSolution(int S[9][9])
{
  for (int i=0; i<9; i++)
  {
    for (int j=0; j<9; j++)
      cout << S[i][j] << " ";
    cout << endl;
  }
}

bool check(int S[9][9], int x, int y, int c)
{
  //check square
  int sx = x / 3;
  int sy = y / 3;
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
    {
      if (S[sy*3+j][sx*3+i] == c)
      {
        return false;
      }
    }

  //check row
  for (int i=0; i<9; i++)
  {
    if (S[i][x] == c)
    {
      return false;
    }
  }

  //check column
  for (int i=0; i<9; i++)
  {
    if (S[y][i] == c)
    {
      return false;
    }
  }
  return true;
}

bool sudoku(int S[9][9], int i)
{
  set<int> C;
  int x = i % 9;
  int y = i / 9;
  bool fixed = false;
  if (i <= 80)
  {
    if (S[y][x] != 0)
    {
      C.insert(S[y][x]);
      fixed = true;
    }
    else
      for (int c=1; c<=9; c++)
      {
        if (check(S,x,y,c))
          C.insert(c);
      }
  }
  for (set<int>::iterator c=C.begin(); c!=C.end(); c++)
  {
    S[y][x] = *c;
    if (i == 80)
    {
      processSolution(S);
      return true;
    }
    if (sudoku(S, i+1))
    {
      return true;
    }
  }
  if (!fixed)
    S[y][x] = 0;
  return false;
}

int main()
{
  int S[9][9] = {
    {2, 5, 0, 0, 9, 0, 0, 7, 6},
    {0, 0, 0, 2, 0, 4, 0, 0, 0},
    {0, 0, 1, 5, 0, 3, 9, 0, 0},
    {0, 8, 9, 0, 0, 5, 2, 6, 0},
    {1, 0, 0, 0, 2, 0, 0, 0, 4},
    {0, 2, 5, 6, 0, 0, 7, 3, 0},
    {0, 0, 8, 3, 0, 2, 1, 0, 0},
    {0, 0, 0, 9, 0, 7, 0, 0, 0},
    {3, 7, 0, 0, 8, 0, 0, 9, 2}};

  if (!sudoku(S, 0))
    cout << "Could not find a solution for the given sudoku" << endl;

  return 0;
}
