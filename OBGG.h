#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>

using Matrix = std::vector< std::vector<double> >;

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
