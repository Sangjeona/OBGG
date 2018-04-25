#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>

using Matrix = std::vector< std::vector<double> >;
using Vector = std::vector<double>;


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
  for (unsigned int i = 0; i < mtx.size(); ++i)
  {
    if (mtx[i][i] == 0)
    {
      auto temp = mtx[i];
      bool check = false;
      for (unsigned int j = i+1; j < mtx.size(); ++j)
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
        printf("Error: No unique solution.\n");
        exit(3);
      }
    }
    for (unsigned int j = i+1; j < mtx.size(); ++j)
    {
      double tmp = mtx[j][i]/mtx[i][i];
      for (unsigned int k = i; k <= mtx.size(); ++k)
        mtx[j][k] -= (mtx[i][k] * tmp);
    }
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


void OBGG (std::string fileName)
{
  // parse the file
  Matrix mtx = parseFile(fileName);
  // and print it
  printf("Matrix:\n");
  printf(printMatrix(mtx).c_str());
  // and create the vector
  Vector ans = GaussElem(mtx);
  printf("Solution:\n");
  for (auto & x : ans)
    printf("%g,\t", x);
  printf("\n");
};
