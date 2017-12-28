#include <iostream>
#include <string>
#include <vector>

int main()
{
  std::string hello("Hello world!");
  std::vector<std::string> helloAll(100, hello);
  auto iter = helloAll.begin();

  while(iter != helloAll.end())
  {
    std::cout << *iter++ << std::endl;
  }
  return 0;
}
