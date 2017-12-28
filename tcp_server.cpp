#include <sys/socket.h>
#include <sys/types.h>


void Start(const char *pcszIP, int nPort)
{
  int hSocket = 0;
  int hPeer = 0;
  int nMaxConn = 20;
  sockaddr_in addr;

  bzero(&addr, sizeof(sockaddr_in));
  addr.sin_port = nPort;
  addr.sin_port = htons(addr.sin_port);
  inet_aton(pcszIP, &addr.sin_addr);
  addr.sin_family = AF_INET;

  hSocket = socket(AF_INET, SOCK_STREAM, 0);
  if(-1 == bind(hSocket, (sockaddr*)&addr, sizeof(sockaddr_in)))
    perror("bind");
  if(-1 == listen(hSocket, nMaxConn))
    perror("listen");
  while(true)
  {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    hPeer = accept(hSocket, (sockaddr *)&addr, &size);
    recv(hPeer, buffer, sizeof(buffer), 0);
}
  
void ()
{
  int hPeer = 0;
  
  while(true)
  {
    

int main(int argc, char *args[])
{
  int nPort = 0;
  std::string strIPSelf("127.0.0.1");

  if(argc < 2)
  {
    std::cout << "at least one param as port!" << std::endl;
    return -1;
  }
  else if(2 == argc)
    nPort = aton(args[1]);
  else if(3 == argc)
  {
    nPort = aton(args[2]);
    strIPSelf.assign(args[1]);
  }
  
  Start(strIPSelf.c_str(), nPort);
  return 0;
} 
