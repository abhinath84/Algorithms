#include <iostream>

#include "quick_find.h"


void checkUF(UF &cuf);
void checkQuickUnionUF(QuickUnionUF &cuf);
void checkWeightedQuickUnionUF(WeightedQuickUnionUF &cuf);

int main(int argc, char **argv)
{
  UF uf(20);
  QuickUnionUF quf(20);
  WeightedQuickUnionUF wquf(20);

  // union
  checkUF(uf);

  std::cout << std::endl;
  std::cout << std::endl;

  checkQuickUnionUF(quf);

  std::cout << std::endl;
  std::cout << std::endl;

  checkWeightedQuickUnionUF(wquf);

  system("pause");
  return(0);
}

void checkUF(UF &cuf)
{
  cuf.Union(4, 3);
  cuf.Union(3, 8);
  cuf.Union(6, 5);

  if(cuf.Connected(8, 9))
    std::cout << "--- (8, 9) -> Connected ---" << std::endl;
  else
    std::cout << "--- (8, 9) -> Not Connected ---" << std::endl;

  cuf.Union(9, 4);
  cuf.Union(2, 1);

  if(cuf.Connected(8, 9))
    std::cout << "--- (8, 9) -> Connected ---" << std::endl;
  else
    std::cout << "--- (8, 9) -> Not Connected ---" << std::endl;

  std::cout << std::endl;
  if(cuf.Connected(1, 0))
    std::cout << "--- (1, 0) -> Connected ---" << std::endl;
  else
    std::cout << "--- (1, 0) -> Not Connected ---" << std::endl;

  cuf.Union(5, 0);
  cuf.Union(7, 2);
  cuf.Union(6, 1);

  if(cuf.Connected(1, 0))
    std::cout << "--- (1, 0) -> Connected ---" << std::endl;
  else
    std::cout << "--- (1, 0) -> Not Connected ---" << std::endl;
}

void checkQuickUnionUF(QuickUnionUF &cuf)
{
  cuf.Union(4, 3);
  cuf.Union(3, 8);
  cuf.Union(6, 5);

  if(cuf.Connected(8, 9))
    std::cout << "--- (8, 9) -> Connected ---" << std::endl;
  else
    std::cout << "--- (8, 9) -> Not Connected ---" << std::endl;

  cuf.Union(9, 4);
  cuf.Union(2, 1);

  if(cuf.Connected(8, 9))
    std::cout << "--- (8, 9) -> Connected ---" << std::endl;
  else
    std::cout << "--- (8, 9) -> Not Connected ---" << std::endl;

  std::cout << std::endl;
  if(cuf.Connected(1, 0))
    std::cout << "--- (1, 0) -> Connected ---" << std::endl;
  else
    std::cout << "--- (1, 0) -> Not Connected ---" << std::endl;

  cuf.Union(5, 0);
  cuf.Union(7, 2);
  cuf.Union(6, 1);

  if(cuf.Connected(1, 0))
    std::cout << "--- (1, 0) -> Connected ---" << std::endl;
  else
    std::cout << "--- (1, 0) -> Not Connected ---" << std::endl;
}

void checkWeightedQuickUnionUF(WeightedQuickUnionUF &cuf)
{
  cuf.Union(4, 3);
  cuf.Union(3, 8);
  cuf.Union(6, 5);

  if(cuf.Connected(8, 9))
    std::cout << "--- (8, 9) -> Connected ---" << std::endl;
  else
    std::cout << "--- (8, 9) -> Not Connected ---" << std::endl;

  cuf.Union(9, 4);
  cuf.Union(2, 1);

  if(cuf.Connected(8, 9))
    std::cout << "--- (8, 9) -> Connected ---" << std::endl;
  else
    std::cout << "--- (8, 9) -> Not Connected ---" << std::endl;

  std::cout << std::endl;
  if(cuf.Connected(1, 0))
    std::cout << "--- (1, 0) -> Connected ---" << std::endl;
  else
    std::cout << "--- (1, 0) -> Not Connected ---" << std::endl;

  cuf.Union(5, 0);
  cuf.Union(7, 2);
  cuf.Union(6, 1);

  if(cuf.Connected(1, 0))
    std::cout << "--- (1, 0) -> Connected ---" << std::endl;
  else
    std::cout << "--- (1, 0) -> Not Connected ---" << std::endl;

  WeightedQuickUnionUF tmp(cuf);
}
