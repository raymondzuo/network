#include "../../unpv13e/lib/unp.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
    int listenfd, connfd;
    char buff[MAXLINE];
    struct sockaddr_in servaddr;
    time_t ticks;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(& servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
    Listen(listenfd, LISTENQ);

    for(; ;)
    {
        connfd = Accept(listenfd, (SA *) NULL, NULL);
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "haha:  %.24s\r\n", ctime(&ticks));
        Write(connfd, buff, strlen(buff));

        close(connfd);
    }

    return 0;
}