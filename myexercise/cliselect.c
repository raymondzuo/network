#include "../../unpv13e/lib/unp.h"

extern void str_cli_select(FILE *fp, int sockfd);

int main(int argc, char ** argv)
{
    int sockfd;
    struct sockaddr_in servaddr;

	if (argc != 2)
		err_quit("usage: cliselect <IPaddress>");

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    Connect(sockfd, (SA *)&servaddr, sizeof(servaddr));

    str_cli_select(stdin, sockfd);

    exit(0);
}