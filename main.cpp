#include <iostream>
#include "BiList.hpp"
#include "testfun.hpp"

int main()
{
  int data[] = {10, 20, 30};
  BiList<int>* list = convert(data, 3);
  add(list->next, 5);

  BiList<int>* n20 = list->next->next->next;
  insert(n20, 25);

  std::cout << "All elements: ";
  traverse(PrintM<int>(), list->next, list);
  std::cout << "\n";

  SumM<int> s = traverse(SumM<int>(), list->next, list);
  std::cout << "Sum of elements: " << s.total << "\n";

  clear(list->next, list);
  delete list;
  return 0;
}
