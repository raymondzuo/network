#include "../../unpv13e/lib/unp.h"
#include <stdio.h>

int main(int argc, char ** argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if(2 != argc)
    {
        printf("Usage: myclient <IP Address> \n");
        exit(-1);
    }
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)    
    {
        printf("Create socket error, error code : %d \n", sockfd);
        exit(-1);
    }
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);
    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    {
        printf("Error when convert address! \n");
        exit(-1);
    }
    if(connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("Connect error !!\n");
        exit(-1);
    }

    while((n = read(sockfd, recvline, MAXLINE)) > 0)
    {
        recvline[n] = 0;
        if(fputs(recvline, stdout) == EOF) 
        {
            printf("EOF !!\n");
            break;
        }
    }

    if(n < 0)
        printf("Read error !!\n");

    return 0;
}
