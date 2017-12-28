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

static const int G_TIME_OUT = 30;


// returns a connected socket
int connSocket()
{
    int hSocket = 0;
    int ret = 0;
    int err = 0;
    timeval tTimeout;
    fd_set wfds;
    std::string strIP("192.168.100.245");
    static const short nPort = 30000;
    sockaddr_in addr;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    inet_aton(strIP.c_str(), &addr.sin_addr);
    addr.sin_port = htons(nPort);

    tTimeout.tv_sec = G_TIME_OUT;
    tTimeout.tv_usec = 0;

    while(true)
    {
        hSocket = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
        FD_ZERO(&wfds);
        FD_SET(hSocket, &wfds);
        //if(!FD_ISSET(hSocket, &wfds))
        //    return 0;
        connect(hSocket, (sockaddr*)(&addr), sizeof(sockaddr_in));
        ret = select(2, 0, &wfds, 0, &tTimeout);
        if(1 > ret)
        {
            std::cout << "CONNECT ISSUE: " << strerror(err) << std::endl;
            close(hSocket);
            hSocket = 0;
        }
        break;
    }
    return hSocket;
}


int main()
{
    int handle = 0;
    int ret = 0;
    char buffer[2048];

    memset(buffer, 'a', 1000);
    buffer[1000] = '\0';
    handle = connSocket();

    write(handle, buffer, strlen(buffer)+1);
    close(handle);

    return 0;
}
