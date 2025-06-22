
//target ip address ad port range
// use sockets to check if a port is open
//output: list of open ports and their associated services(eg: 80/HTTP, 22/ssh)
//learning...

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
    int sock;
    struct sockaddr_in target;
    char ip[] = "127.0.0.1"; //replace with target ip
    int start_port = 1, end_port = 100;

    for(int port = start_port; port <= end_port; port++){
        sock = socket(AF_INET, SOCK_STREAM,0);
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        target.sin_addr.s_addr = inet_addr(ip);

        if (connect(sock, (struct sockaddr*)&target, sizeof(target))==0){
            printf("Port %d is open \n", port);
        }
        close(sock);
    }
    return 0;
}