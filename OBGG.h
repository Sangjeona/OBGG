#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>

using Matrix = std::vector< std::vector<double> >;
using Vector = std::vector<double>;

void OBGG ();

std::string printMatrix (Matrix mtx)
{
  std::string ans = "";
  for (auto & x : mtx)
  {
    for (auto & y : x) ans += std::to_string(y) + "\t";
    ans += '\n';
  }
  return ans;
}

Matrix parseFile (std::string fileName)
{
  // create a std::ifstream object
  std::ifstream myfile;
  myfile.open(fileName);
  if (myfile.fail())  // check for existence
  {
    printf("File %s not found.\n", fileName.c_str());
    exit(2);
  }
  int m = 0, n = 0;  // number of rows, columns
  myfile >> m >> n;
  if (n != (m+1))
  {
    printf("File %s contains an invalid matrix.\n", fileName.c_str());
    exit(1);
  }
  // and now create the Matrix object
  Matrix mtx (m, std::vector<double> (n, 0.0));
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      myfile >> mtx[i][j];
  return mtx;
}

Vector GaussElem(Matrix mtx)
{
  Vector sol (mtx.size(), 0.0);
  for (int i = 0; i < mtx.size(); i++)
  {
    printf("i is %i.\n", i);
    if (mtx[i][i] == 0)
    {
      auto temp = mtx[i];
      bool check = false;
      for (int j = i+1; j < mtx.size(); j++)
      {
        if (mtx[j][i] != 0)
        {
          mtx[i] = mtx[j];
          mtx[j] = temp;
          check = true;
          break;
        }
      }
      if (check == false)
      {
        printf("No fuck you lol.\n");
        return sol;
      }
    }
    for (int j = i+1; j < mtx.size(); ++j)
    {
      for (int k = 0; k <= mtx.size(); ++k)
      {
        printf("(%i,%i)\n", j, k);
        mtx[j][k] -= mtx[i][k] * mtx[j][i] / mtx[i][i];
      }
    }
    printf(printMatrix(mtx).c_str());
  }

  for (int i = (mtx.size() - 1); i >= 0; --i)
  {
    // für Judd
    // ihre Liebe
    // OBGG
    for (int j = (mtx.size()-1); j >= (i+1); j--)
    {
      sol[i] -= mtx[i][j] * sol[j];
    }
    sol[i] += mtx[i][mtx.size()];
    sol[i] /= mtx[i][i];
  }
  return sol;
}
