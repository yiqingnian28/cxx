#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define MAXLINE 4096

int main(int argc, char** argv)
{
    int    listenfd, connfd;
    struct sockaddr_in     servaddr;
    char    buff[4096];
    int     n;

    if( (listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1 ){
		printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
		exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(6666);

    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
		printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
		exit(0);
    }

    if( listen(listenfd, 10) == -1){
		printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
		exit(0);
    }

    printf("======waiting for client's request======\n");
    while(1){
		if( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1){
			printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
			continue;
		}
		
		/*
		while( n = recv(connfd, buff, MAXLINE, 0) != 0 &&
			   strcmp(buff, "bye")){
			   
			printf("recv msg from client: %s, n=%d\n", buff,n);
			memset(buff, 0x00, sizeof(buff));
		}
		*/
		for(;;){
			n = recv(connfd, buff, MAXLINE, 0);
			
			if( n == 0 || n == -1){
				printf("connection shut down...\n");
				break;
			}
			
			buff[n] = '\0';
			printf("recv msg from client: %s, n=%d\n", buff,n);
		}
		close(connfd);
    }

    close(listenfd);
}