#include <iostream>
#include <cstdio>
#include "OBGG.h"

int main(int argc, char** argv)
{
  Matrix mtx;
  if (argc > 1)
    mtx = parseFile(argv[1]);
  else
  {
    std::string fname = "";
    while (fname == "")
    {
      printf("Enter filename: ");
      std::getline(std::cin, fname);
    }
    mtx = parseFile(fname);
  }
  printf("Matrix:\n");
  printf(printMatrix(mtx).c_str());
  
  // now print out the goddamn vector
  auto ans = GaussElem(mtx);
  printf("Answer lol:\n");
  for (auto & x : ans)
    printf("%g,\t", x);
  printf("\n");
}
