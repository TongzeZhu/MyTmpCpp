#include <cerrno>
#include <iostream>

int main()
{
  std::string strTemp("socket");
  int ret = 0;
  
  std::cout << ret << std::endl;
  perror(strTemp.c_str());
  return 1;
}
