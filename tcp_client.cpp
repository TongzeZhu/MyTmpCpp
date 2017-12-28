#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <string>
#include <cstring>
#include <iostream>
#include <cerrno>

int main()
{
  int handle = 0;
  int ret = 0;
  std::string strIP("127.0.0.1");
  static const short nPort = 9000;
  sockaddr_in addr;

  handle = socket(AF_INET, SOCK_STREAM | SOCK_CLOEXEC, 0);

  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  inet_aton(strIP.c_str(), &addr.sin_addr);
  addr.sin_port = htons(nPort);
  ret = connect(handle, (struct sockaddr*)(&addr), sizeof(addr));

  if(ret < 0)
    std::cout << strerror(errno) << std::endl;
    //perror("conn error");
  close(handle);

  return 0;
}
