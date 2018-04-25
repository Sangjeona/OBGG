#include <iostream>
#include <cstdio>
#include "OBGG.h"

int main(int argc, char** argv)
{
  Matrix mtx;
  if (argc > 1)
    OBGG(argv[1]);
  else
  {
    std::string fname = "";
    while (fname == "")
    {
      printf("Enter filename: ");
      std::getline(std::cin, fname);
    }
    OBGG(fname);
  }

}
